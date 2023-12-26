#include <iostream>
#include <queue>
#include <vector>
using namespace std;

bool bfs(int start, vector<int>& color, vector<vector<int>>& graph) {
    if (color[start] != 0) {
        return true;
    }

    queue<int> q;
    q.push(start);
    color[start] = 1;

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        for (int neighbor : graph[current]) {
            if (color[neighbor] == color[current]) {
                return false;  
            } else if (color[neighbor] == 0) {
                q.push(neighbor);
                color[neighbor] = -color[current];  
            }
        }
    }

    return true;
}
bool isBipartite(vector<vector<int>> graph) {      
    int n = graph.size();
    vector<int> color(n, 0);

    for (int i = 0; i < n; ++i) {
        if (!bfs(i, color, graph)) {
            return false;
        }
    }
    return true;
}




int main (){
    int G[6][6] = { {0, 1, 0, 0, 0, 1},
                {1, 0, 1, 0, 0, 0},
                {0, 1, 0, 1, 0, 0},
                {0, 0, 1, 0, 1, 0},
                {0, 0, 0, 1, 0, 1},
                {1, 0, 0, 0, 1, 0} };
    int n = 6;

    vector<vector<int>> graph(n, vector<int>());
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (G[i][j]) graph[i].push_back(j);
        }
    }

    bool a = isBipartite(graph) ;
    cout<<a;
    return 0;
}