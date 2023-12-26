#include <iostream>
#include <list>
#include <queue>
#include <bits/stdc++.h>
using namespace std;

class Adjacency
{
private:
	list<int> adjList;
	int size;
public:
	Adjacency() {}
	Adjacency(int V) {}
	void push(int data)
	{
		adjList.push_back(data);
		size++;
	}
	void print()
	{
		for (auto const &i : adjList)
			cout << " -> " << i;
	}
	void printArray()
	{
		for (auto const &i : adjList)
			cout << i << " ";
	}
	int getSize() { return adjList.size(); }
	int getElement(int idx) 
	{
		auto it = adjList.begin();
		advance(it, idx);
		return *it;
	}
};
#include <stack>
class Graph
{
private:
	int V;
	Adjacency *adj;

public:
	Graph(int V)
	{
		this->V = V;
		adj = new Adjacency[V];
	}
	
	void addEdge(int v, int w)
	{
		adj[v].push(w);
		adj[w].push(v);
	}
	
    void printGraph()
	{
		for (int v = 0; v < V; ++v)
		{
			cout << "\nAdjacency list of vertex " << v << "\nhead ";
			adj[v].print();
		}
	}
	
	Adjacency *DFS(int v)
    {
        // v is a vertex we start DFS
        Adjacency* result = new Adjacency(V);
        bool * visited = new bool [V];
        for(int i = 0; i < V; i++){
            visited[i] = false;
        }
        stack<int> q;
        q.push(v);
        visited[v] = true;
        while(!q.empty()){
            int curr = q.top(); q.pop();
            result->push(curr);
            for(int i = 0; i < adj[curr].getSize(); i++){
                int tmp = adj[curr].getElement(i);
                if(!visited[tmp]){
                    visited[tmp] = true;
                    q.push(tmp);
                }
            }
        }
        delete [] visited;
        return result;
	}
};

int main (){
    int V = 8, visited = 0;

Graph g(V);
Adjacency *arr;
int edge[][2] = {{0,1}, {0,2}, {0,3}, {0,4}, {1,2}, {2,5}, {2,6}, {4,6}, {6,7}};
for(int i = 0; i < 9; i++)
{
 g.addEdge(edge[i][0], edge[i][1]);
}

// g.printGraph();
// cout << endl;
arr = g.DFS(visited);
arr->printArray();
delete arr;
}