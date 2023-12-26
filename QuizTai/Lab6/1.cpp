#include <iostream>
#include <list>
#include <vector>
#include <queue>

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

#include <vector>
#include <queue>
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
	
	Adjacency *BFS(int v)
    {
        Adjacency *arr = new Adjacency[V]; 
        int i = 0;
        vector<bool> Visited(V, false);
        queue<int> q;
        Visited[v] = true;
        q.push(v);
        while (!q.empty())
        {
            int curr = q.front();
            q.pop();
            arr[i++] = adj[curr];

            for (int j = 0; j < adj[curr].getSize(); j++)
            {
                int tmp = adj[curr].getElement(j);
                if (!Visited[tmp])
                {
                    Visited[tmp] = true;
                    q.push(tmp);
                }
            }
        }
        return arr;
    }
};



int main (){
    int V = 6;
int visited = 2;

Graph g(V);
Adjacency* arr = new Adjacency(V);
int edge[][2] = {{0,1},{0,2},{1,3},{1,4},{2,4},{3,4},{3,5},{4,5}};
    
for(int i = 0; i < 8; i++)
{
    g.addEdge(edge[i][0], edge[i][1]);
}
    
arr = g.BFS(visited);
arr->printArray();
delete arr;
}