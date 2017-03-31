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

void PrintList(vector<list<int> > &lst) {
    for (int i = 0; i < lst.size(); i++) {
        cout << i << ": ";
        for (list<int>::iterator ip = lst[i].begin(); ip != lst[i].end(); ip++) {
            cout << *ip << " ";
        }
        cout << endl;
    }
}


class Graph {
    int numNodes;
    vector<list<int> > outlist;
    vector<list<int> > inlist;
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
        return inlist[vertex].size();
    }

    int OutDegree(int vertex) {
        return outlist[vertex].size();
    }

    bool isNeighborDownStream(int neigh, int source) {
        for (list<int>::iterator ip = inlist[source].begin(); ip != inlist[source].end(); ip++) {
            if (*ip == neigh) {
                return true;
            }
        }
        return false;
    }

    bool isNeighborUpStream(int neigh, int source) {
        for (list<int>::iterator ip = outlist[source].begin(); ip != outlist[source].end(); ip++) {
            if (*ip == neigh) {
                return true;
            }
        }
        return false;
    }

    bool isReachable(int target, int source) {
        bool reachable = false;
        for (list<int>::iterator ip = outlist[source].begin(); ip != outlist[source].end(); ip++) {
            if (*ip == target) {
                return true;
            } else {
                reachable = isReachable(*ip, source);
            }
            if (reachable == true) {
                return true;
            }
        }
        return reachable;
    }


    void addEdge(int s, int t) {
        numNodes++;
        int edge = getSize() - 1;
        inlist.resize(numNodes);
        outlist.resize(numNodes);

        outlist[edge].push_back(t);
        inlist[t].push_back(edge);
    }

    int getSize() {
        return numNodes;
    }

    void ReadFromFile(string fn) {
        ifstream ifs;
        int s, t;

        ifs.open(fn, std::ifstream::in);
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

int main() {
    Graph g("/Users/veraxmedax/Documents/boun/courses/swe501/hw6/data.txt");
    g.Print();

    for (int j = 0; j < g.getSize(); j++) {
        cout << "outDegree(" << j << "): " << g.OutDegree(j) << endl;
    }

    for (int i = 0; i < g.getSize(); i++) {
        cout << "inDegree(" << i << "): " << g.InDegree(i) << endl;
    }

    cout << "isNeighborDownStream(0, 1): " << g.isNeighborDownStream(0, 1) << endl;
    cout << "isNeighborUpStream(3, 2): " << g.isNeighborUpStream(3, 2) << endl;
    cout << "isNeighborUpStream(2, 3): " << g.isNeighborUpStream(2, 3) << endl;

    cout << "isReachable(3, 0): " << g.isReachable(3, 0) << endl;

    g.addEdge(4, 2);
    cout << "Print after addEdge(4, 2) called" << endl;
    g.Print();

    return 0;
}
