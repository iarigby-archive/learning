// trace-pc-guard-example.cc
void foo() { }
void foo2() { }
int main(int argc, char **argv) {
  if (argc > 1) foo();
  if (argc < 1) foo2();
}