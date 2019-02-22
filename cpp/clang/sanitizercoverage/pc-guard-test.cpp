#include <iostream>
#include <vector>
#include "functionPointerMap.h"
#include <string>

std::map<std::vector<string>, std::vector<char> v> pcCalls;
// trace-pc-guard-example.cc
using permutations = std::vector<std::vector<string>>;

int main(int argc, char **argv) {
	/*FunctionPointerMap<stack<int>> a1;
	a1.insert("push", &stack<int>::push);
	a1.insert("pop", &stack<int>::pop);
	a1.insert("peek", &stack<int>::peek);
	a1.insert("size", &stack<int>::size);
	a1.insert("isEmpty", &stack<int>::isEmpty);
	a1.insert("isFull", &stack<int>::isFull);*/
	std::vector<string> v;
	v.push("a");
	v.push("b");
	v.push("c");
	permutations p = getAllPossibleSequences(v, 4);

	//for
	// stack<int> s(5);
}

permutations getAllPossibleSequences(std::vector<string> v, int maxSize) {
	permutations p; 
	// get all subsets
	permutations allSubsets;

	for (auto iter = v.begin(); iter != v.end(); ++iter) {
		for (auto setsIter = allSubsets.begin(); setsIter != allSubsets.end(); ++setsIter) {
			std::vector<string> set;
			for (auto setElem = *setsIter.begin(); setElem != *setsIter.end(); ++setElem) {
				set.push(*setElem);
			}
			set.push(*iter);
			allSubsets.push(set);
		}
	}
	// permute all subsets

	return allSubsets;
}