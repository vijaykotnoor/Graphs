/*
 * Graph.cpp
 *
 *  Created on: 20-Nov-2018
 *      Author: vijay
 */
#include <iostream>
#include <queue>
#include "Graph.h"

Graph::Graph():adjList_(),inTime_(), outTime_(), visited_(), undirected_(true), size_(0), timer_(0) {
	// TODO Auto-generated constructor stub

}
Graph::Graph(int size):adjList_(),inTime_(), outTime_(), visited_(),undirected_(true), size_(size),timer_(0) {
	// TODO Auto-generated constructor stub
	std::list<int> a;
	adjList_.assign(size, a);
	inTime_.assign(size_, 0);
	outTime_.assign(size_, 0);
	visited_.assign(size_, 0);

}
Graph::Graph(int size, bool undirected):adjList_(),inTime_(), outTime_(), visited_(),undirected_(undirected), size_(size),timer_(0) {
	// TODO Auto-generated constructor stub
	std::list<int> a;
	adjList_.assign(size, a);
	inTime_.assign(size_, 0);
	outTime_.assign(size_, 0);
	visited_.assign(size_, 0);
}
void Graph::addEdge(int u, int v)
{
	adjList_[u].push_back(v);
	if(undirected_)
		adjList_[v].push_back(u);
}

void Graph::printGraph()
{
	for(auto i = 0; i < adjList_.size(); i++)
	{
		std::cout << "head: " << i;
		for(auto const elem :adjList_[i])
		{
			std::cout << "->" << elem;
		}
		std::cout<<std::endl;
	}
}

void Graph::BFS(int s)
{
	std::vector<bool> visited;
	visited.assign(size_, false);
	visited[s] = true;
	std::queue<int> bfsqueue;
	bfsqueue.push(s);

	while(!bfsqueue.empty())
	{
		s = bfsqueue.front();
		std::cout<< s << " ";
		bfsqueue.pop();
		auto x = adjList_[s];
		for(const auto elem: adjList_[s])
		{
			if(!visited[elem])
			{
				visited[elem] = true;
				bfsqueue.push(elem);
			}
		}

	}
}

void Graph::DFS(int s)
{
	std::vector<bool> visited(size_, false);
	std::stack<int> bfsstack;
	bfsstack.push(s);

	while(!bfsstack.empty())
	{

		s = bfsstack.top();
		bfsstack.pop();
		if(!visited[s])
		{
			std::cout<< s << " ";
			visited[s] = true;

		}

		for(const auto elem: adjList_[s])
		{
			if(!visited[elem])
			{
				bfsstack.push(elem);
			}
		}

	}
}

void Graph::topoSort()
{
	std::vector<bool> visited(size_, false);
	std::stack<int> dfsStack;
	std::stack<int> topoSortStack;

	for(auto i = 0 ; i < size_ ; i++)
	{


		if(!visited[i])
		{
		dfsStack.push(i);

		while(!dfsStack.empty())
		{

			auto s = dfsStack.top();
			dfsStack.pop();
			if(visited[s])
			{
				topoSortStack.push(s);
				continue;

			}

			visited[s] = true;
            auto allvisited = true;
			for(const auto elem: adjList_[s])
			{
				if(!visited[elem])
				{
					allvisited = false;
					dfsStack.push(elem);
				}
			}


		}

	}



	}

    std::cout << "topoSortStack.size()"<<topoSortStack.size()<< std::endl;
	while(!topoSortStack.empty())
	{

		std::cout<< topoSortStack.top()<<  " " ;
		topoSortStack.pop();
	}
}

void Graph::topoSortRec()
{
	std::vector<bool> visited(size_, false);
	std::stack<int> topoStack;

	for(int i = 0; i < size_; i++)
	{
		if(!visited[i])
		{
			topoSortStackUtil(i, visited, topoStack);
		}
	}

	while(!topoStack.empty())
	{
		std::cout<< " "<<topoStack.top();
				topoStack.pop();
	}

}
void Graph::topoSortRecUtil(int s, std::vector<bool>& visited, std::stack<int>& topoStack)
{
	   visited[s] = true;

		std::cout<<"topo start: " << s << std::endl;
	   for(const auto elem: adjList_[s])
	   {
		   if(!visited[elem])
		   {
			   topoSortRecUtil(elem, visited, topoStack);
		   }
	   }
		std::cout<<"topo end: " << s << std::endl;
	   topoStack.push(s);

}

void Graph::topoSortStackUtil(int s, std::vector<bool>& visited, std::stack<int>& topoStack)
{


		//std::vector<bool> visited(size_, false);
		std::stack<int> bfsstack;
		bfsstack.push(s);

		while(!bfsstack.empty())
		{
			s = bfsstack.top();
			bfsstack.pop();
			if(!visited[s])
			{
				visited[s] = true;
			}

			for(const auto elem: adjList_[s])
			{
				if(!visited[elem])
				{
					bfsstack.push(elem);
				}
			}

		}
		std::cout<<"topo start: " << s << std::endl;
	   for(const auto elem: adjList_[s])
	   {
		   if(!visited[elem])
		   {
			   topoSortRecUtil(elem, visited, topoStack);
		   }
	   }
		std::cout<<"topo end: " << s << std::endl;
	   topoStack.push(s);

}

void Graph::DFStimer(int root)
{
	visited_[root] = true;
	inTime_[root]= ++timer_;
	for(const auto elem: adjList_[root])
	{
		if(!visited_[elem])
			DFStimer(elem);
	}

    outTime_[root] = ++timer_;

}

void Graph::DFSUtil(int s, std::vector<bool>& visited)
{
	visited[s] = true;
	for(const auto elem: adjList_[s])
	{
		if(!visited[elem])
			DFSUtil(elem, visited);
	}
}

int Graph::findMother()
{
	std::vector<bool> visited(size_, false);

	int v = 0;

	for(auto i = 0 ; i <size_ ; i++)
	{
		if(!visited[i])
		{
			DFSUtil(i, visited);
			v = i;
		}
	}


	visited.assign(size_, false);

	DFSUtil(v, visited);
	for(auto elem: visited)
	{
		if(!elem)
			return -1;
	}

	return v;
}

bool Graph::query(int v , int u)
{
	return (inTime_[v] < inTime_[u] && outTime_[v] >outTime_[u]) || (inTime_[u] < inTime_[v] && outTime_[u] >outTime_[v]);
}

bool Graph::isCyclic()
{
	std::vector<bool> visited(size_, false);
	std::vector<bool> recStack(size_, false);

	for(auto i = 0; i<size_; i++)
	{

			if(isCyclicUtil(i,visited, recStack))
				return true;

	}
	return false;

}

bool Graph::isCyclicUtil(int s, std::vector<bool>& visited , std::vector<bool>& recStack)
{
	if(!visited[s])
	{
		visited[s] = true;
		recStack[s] = true;
		for(const auto elem: adjList_[s])
		{
			if(recStack[elem])
				return true;
			if(!visited[elem])
			{
				if(isCyclicUtil(elem,visited, recStack))
					return true;
			}
		}
	}
   recStack[s] = false;
   return false;
}

bool Graph::isCyclicUd()
{
	std::vector<bool> visited(size_, false);


	for(auto i = 0; i<size_; i++)
	{
          if(!visited[i])
			if(isCyclicUtilUd(i,visited, -1))
				return true;

	}
	return false;

}

bool Graph::isCyclicUtilUd(int s, std::vector<bool>& visited , int parent)
{

		visited[s] = true;
		for(const auto elem: adjList_[s])
		{
			if(!visited[elem])
			{
				if(isCyclicUtilUd(elem,visited, s))
					return true;
			}
			else if(elem != parent)
				return true;
		}

   return false;
}

bool Graph::isCyclicColor()
{
    std::vector<color> visited(size_, color::WHITE);
    for(auto i = 0; i < size_; i++)
    {
    	if(visited[i] != color::BLACK)
    	{
    		if(isCyclicUtilColor(i, visited))
    			return true;
    	}
    }
    return false;
}

bool Graph::isCyclicUtilColor(int s, std::vector<color>& visited)
{
	visited[s] = color::GRAY;
	for(const auto elem : adjList_[s])
	{
		if(visited[elem] == color::GRAY)
			return true;
		if(visited[elem] == color::WHITE && isCyclicUtilColor(elem, visited))
			return true;

	}
    visited[s] = color::BLACK;
    return false;
}

void Graph::isBridge()
{
	std::vector<bool> visited(size_, false);
	std::vector<int> discovery(size_, 0);
	std::vector<int> low(size_, 0);
	std::vector<int> parent(size_, -1);
	for(auto i =0; i< size_; i++)
	{
		if(!visited[i])
			isBridgeUtil(i, visited, discovery, low, parent);

	}

}

void Graph::isBridgeUtil(int s, std::vector<bool>& visited,std::vector<int>& discovery,
		std::vector<int>& low, std::vector<int>& parent)
{
     visited[s] = true;
     low[s] = discovery[s] = ++timer_;
     for(const auto elem: adjList_[s])
     {

    	 if(!visited[elem])
    	 {
    		 parent[elem] = s;
    		 isBridgeUtil(elem, visited, discovery, low, parent);

    		 low[s] = std::min(low[s], low[elem]);

    		 if(low[elem] > discovery[s])
    			 std::cout<< elem << " " << s << std::endl;
    	 }


    	 else if(elem != parent[s])
    		 low[s] = std::min(low[s], discovery[elem]);
     }

}
Graph::~Graph() {
	// TODO Auto-generated destructor stub
}

