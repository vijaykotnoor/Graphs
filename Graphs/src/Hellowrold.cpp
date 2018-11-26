//============================================================================
// Name        : Hellowrold.cpp
// Author      : Vijay
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Graph.h"
using namespace std;

int main() {




	 // Create graphs given in above diagrams
	    cout << "\nBridges in first graph \n";
	    Graph g1(5);
	    g1.addEdge(1, 0);
	    g1.addEdge(0, 2);
	    g1.addEdge(2, 1);
	    g1.addEdge(0, 3);
	    g1.addEdge(3, 4);
	    g1.isBridge();

	    cout << "\nBridges in second graph \n";
	    Graph g2(4);
	    g2.addEdge(0, 1);
	    g2.addEdge(1, 2);
	    g2.addEdge(2, 3);
	    g2.isBridge();

	    cout << "\nBridges in third graph \n";
	    Graph g3(7);
	    g3.addEdge(0, 1);
	    g3.addEdge(1, 2);
	    g3.addEdge(2, 0);
	    g3.addEdge(1, 3);
	    g3.addEdge(1, 4);
	    g3.addEdge(1, 6);
	    g3.addEdge(3, 5);
	    g3.addEdge(4, 5);
	    g3.isBridge();
	return 0;
}
