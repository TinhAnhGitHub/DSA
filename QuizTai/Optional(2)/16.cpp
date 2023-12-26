#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool bfs(int start, vector<int>& color, vector<vector<int>> graph){
    if(color[start] != 0){
        return true; //* this node has been visited
    }
    queue<int>q;
    q.push(start);
    color[start] = 1;
    while(!q.empty()){
        int curr = q.front();
        q.pop();
        for(int neightbor : graph[curr]){
            if(color[neightbor] == color[curr]){
                //* the color of the neighbor and the curr must be in different color, so return false
                return false;
            }else if( color[neightbor] == 0){
                color[neightbor] = - color[curr]; //* Assign it to opposite set of Curr
                q.push(neightbor); //* Continue consider that node
            }
        }
    }
    return true;
}
bool isBipartite(vector<vector<int>> graph) {
    int n = graph.size();
    vector<int> color (n, 0);

    for(int i = 0; i < n; i++){
        if (!bfs(i, color, graph)){
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

isBipartite(graph) ? cout << "Yes" : cout << "No";
}
