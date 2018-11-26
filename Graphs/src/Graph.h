/*
 * Graph.h
 *
 *  Created on: 20-Nov-2018
 *      Author: vijay
 */
#include <vector>
#include <stack>
#include <list>
#ifndef GRAPH_H_
#define GRAPH_H_


class Graph {
public:

	Graph();
	Graph(int size);
	Graph(int size, bool undirected);
	virtual ~Graph();

    enum class color
	{
    	WHITE,
		GRAY,
		BLACK
	};


	void addEdge(int u, int v);
	void printGraph();
	void BFS(int s);
	void DFS(int s);
	void DFSUtil(int s, std::vector<bool>& visited);
	int findMother();
	bool isCyclic();
	bool isCyclicUtil(int s, std::vector<bool>& visited , std::vector<bool>& recStack);
	bool isCyclicColor();
	bool isCyclicUtilColor(int s, std::vector<color>& visited);
	bool isCyclicUd();
	bool isCyclicUtilUd(int s, std::vector<bool>& visited , int parent);
	void DFStimer(int s);
	void topoSort();
	void topoSortRec();
	void topoSortRecUtil(int s, std::vector<bool>& visited, std::stack<int>& topoStack);
	void topoSortStackUtil(int s, std::vector<bool>& visited, std::stack<int>& topoStack);
	bool query(int v , int u);
	void isBridge();
	void isBridgeUtil(int s, std::vector<bool>& visited, std::vector<int>& discovery,
			std::vector<int>& low, std::vector<int>& parent);

private:
	std::vector<std::list<int>> adjList_;
	std::vector<int> inTime_;
	std::vector<int> outTime_;
	std::vector<bool> visited_;
	bool undirected_;
	int size_;
	int timer_;
};

#endif /* GRAPH_H_ */
