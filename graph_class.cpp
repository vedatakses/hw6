//============================================================================
// Name        : graph_class.cpp
// Author      : 
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>     // std::cout
#include <fstream>      // std::ifstream
#include <list>
#include <vector>
#include <string>

using namespace std;

void PrintList(vector< list<int> >& lst) {
	  for (int i=0; i<lst.size(); i++) {
		  cout << i << ": ";
		  for (list<int>::iterator ip=lst[i].begin(); ip!=lst[i].end(); ip++) {
			  cout << *ip << " ";
		  }
		  cout << endl;
	  }
}


class Graph {
	int numNodes;
	vector< list<int> > outlist;
	vector< list<int> >  inlist;
public:
	Graph(int N) {
		numNodes = N;
		outlist.resize(N);
		inlist.resize(N);
	}

	Graph(string fn) {
		ReadFromFile(fn);
	}


	void Print() {
		cout << "Outlist:" << endl;
		PrintList(outlist);
		cout << "Inlist:" << endl;
		PrintList(inlist);
	}

	int InDegree(int vertex) {

	}
	
	int OutDegree(int vertex) {

	}
	
	bool isNeighborDownStream(int neigh, int source) {
	}

	bool isNeighborUpStream(int neigh, int source) {
	}

	bool isReachable(int target, int source) {
	}
	
	void addEdge(int s, int t) {
	}
	
	
	
	void ReadFromFile(string fn) {
		ifstream ifs;
		int s, t;

		ifs.open (fn, std::ifstream::in);
		ifs >> numNodes;
		inlist.resize(numNodes);
		outlist.resize(numNodes);

		 ifs >> s >> t;
		 while (ifs.good()) {
			outlist[s].push_back(t);
			inlist[t].push_back(s);
			ifs >> s >> t;
		 }
		 ifs.close();
	}
};

int main () {
	Graph g("/Users/cemgil/Downloads/data.txt");
	g.Print();
	return 0;
}
