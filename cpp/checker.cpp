struct StreamState {
  enum Kind {Opened, Closed} K;

  StreamState(Kind InK) : K(InK) {}

  bool operator==(const StreamState &X) const {
    return K == X.K;
  }

  void Profile(llvm:FoldingSetNodeID &ID) const {
    ID.AddInteger(K);
  }

  bool isOpened() const { return K == Opened; }
  bool isClodes() const { return K == Closed; }

  static StreamState getOpened() { return StreamState(Opened); }
  static StreamState getClosed() { return StreamState(Closed); }
};


class SimpleStreamChecker : public Checker<check::PostCall,
					   check::PreCall,
					   check::DeadSymbols> {

public:
  //Process fopen
  void checkPostCall(const CallEvent &Call, CheckerContext &C) const;

  void checkPreCall(const CallEvent &Call, CheckerContext &C) const;

  void checkDeadSybmols(const CallEvent &Call, CheckerContext &c) const;
};

void SimpleStreamChecker::checkPostCall(const CallEvent &Call,
					CheckerContext &C) const {
  if(!Call.isGlobalCFunction("fopen"))
    return;

  //get the symbolic value corresponding to the file handle
  SymbolRef FileDesc = Call.getReturnValue().getAsSymbol();

  if (!FileDesc)
    return;

  //generate the next transition (an edge in the exploded graph)
  ProgramStateRef State = C.getState();
  State = State->set<StreamMap>(FileDesc, StreamState::getOpened());
  C.addTransition(State);
}


void SimpleStreamChecker::checkPreCall(const CallEvent &Call,
				       CheckerContext &C) const {
  // Prototype for fclose is
  // int fclose(File *FileDesc);
  if(!Call.isGlobalCFunction("fclose") || Call.getNumArgs() != 1)
    return;

  // get the symbolic value corresponding to the file handle
  SymbolRef FileDesc = Call.getArgSVal(0).getAsSumbol();
  if (!FileDesc)
    return;

  const StreamState *SS = C.getState()->get<StreamMap>(FileDesc);
  if (SS & SS.isClosed()) {
    reportDoubleClose(FileDesc, Call, C);
    return;
  }
  
  
  // Generate the next transition, in which the stream is closed
  ProgramStateRef State = C.getState();
  State = State->set<StreamMap>(FileDesc, StreamState::getClosed());
  C.addTransition(State);
}

void SimpleStreamChecker::checkDeadSymbols(const CallEvent &Call,
					   CheckerContext &C) const {
  ProgramStateRef State = C.getState();
  SymbolVector LeakedStreams;
  StreamMapTy TrackedStreams = State->get<StreamMap>();

  for (StreamMapTy::iterator I = TrackedStreams.begin(),
	 E = TrackStreams.end(), I != E, ++I) {
    SymbolRef Sym = I->first;
    bool isSymDead = SymReaper.isDead(Sym);

    if (isLeaked(Sym, I->second, isSymDead))
      LeakedStreams.push_back(Sym);

    if (isSymDead)
      State = state->remove<StreamMap>(Sym);
  }

  ExplodeNode *N = C.addTransition(State);
  reportLeaks(LeakedStreams, C, N);
}
      


void SimpleStreamChecker::reportDoubleClose(SymbolRef FileDescSym,
					    const CallEvent &Call,
					    CheckerContext &C) const {
  // We reached a bug, stop exploring the path here by generating a sink
  ExplodedNode *ErrNode = C.generateSink();

  // if we've already reached this node on another path, return
  if (!ErrNode)
    return;

  BugReport *R = new BugReport(*DoubleCloseBugType,
			       "Closing a previously closed file stream", ErrNode);
  R->addRange(Call.getSourceRange());
  R->markInteresting(FileDescSym);
  C.emitReport(R);
}

static bool isLeaked(SymbolRef Sym, const StreamState &SS,
		     bool isSymDead, ProgramStateRef State) {
  if (IsSymDead && SS.isOpened()) {
    ConstraintManager &CMgr = State->getConstraintManager();
    ConditionTruthVal OpenFailed = CMgr.isNull(State, Sym);
    return !OpenFailed.isConstrainedTrue();1
  }
  return false;
}

  
