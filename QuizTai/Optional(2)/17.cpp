#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void bfs(vector<vector<int>> graph, int start) {
	queue<int> q;
	vector<bool> visited(graph.size(), false);
	visited[start] = true;
	q.push(start);
	while (!q.empty()){
	    int node = q.front();
	    q.pop();
	    cout<<node<<" ";
	    for(int neighbor: graph[node]){
	        if (! visited[neighbor]){
	            q.push(neighbor);
	            visited[neighbor] = true;
	        }
	    }
	}
}

int main (){
	int init_graph[10][10] = {  {0, 1, 1, 0, 1, 0, 1, 0, 1, 0},
				    {0, 0, 1, 1, 0, 0, 0, 1, 0, 0},
				    {0, 1, 0, 0, 0, 1, 1, 0, 1, 1},
				    {1, 0, 0, 0, 0, 0, 0, 1, 0, 0},
				    {0, 1, 0, 0, 0, 0, 0, 1, 0, 0},
				    {1, 0, 1, 0, 1, 0, 0, 0, 1, 0},
				    {0, 0, 1, 1, 0, 1, 0, 0, 0, 0},
				    {1, 0, 0, 0, 0, 1, 1, 0, 1, 0},
				    {0, 0, 0, 0, 0, 1, 0, 1, 0, 1},
				    {1, 0, 1, 0, 1, 0, 0, 0, 1, 0} };
	int n = 10;
	vector<vector<int>> graph(n, vector<int>());
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (init_graph[i][j]) graph[i].push_back(j);
		}
	}

	bfs(graph, 0);
}