#include <bits/stdc++.h>
using namespace std;
int MinDist(int* dist, bool* spt, int node) {
    int min = INT_MAX;
    int min_index;

    for (int i = 0; i < node; i++) {
        if (!spt[i] && dist[i] <= min) {
            min = dist[i];
            min_index = i;
        }
    }
    return min_index;
}

int Dijkstra(int** graph, int src, int dst) {
    int NumVertices = sizeof(graph) ;
    int kk = sizeof(graph[0]);
    int* dist = new int[NumVertices];
    bool* spt = new bool[NumVertices];

    for (int i = 0; i < NumVertices; i++) {
        dist[i] = INT_MAX;
        spt[i] = false;
    }
    dist[src] = 0;

    for (int i = 0; i < NumVertices - 1; i++) {
        int u = MinDist(dist, spt, NumVertices);
        spt[u] = true;

        for (int v = 0; v < NumVertices; v++) {
            if (!spt[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
                cout<<dist[v]<<" "<<dist[u]<<" "<<graph[u][v];
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    int result = dist[dst];
    return result;
}


int main (){
    int n = 6;
int init[6][6] = {
{0, 10, 20, 0, 0, 0},
{10, 0, 0, 50, 10, 0},
{20, 0, 0, 20, 33, 0},
{0, 50, 20, 0, 20, 2},
{0, 10, 33, 20, 0, 1},
{0, 0, 0, 2, 1, 0} };

int** graph = new int*[n];
for (int i = 0; i < n; ++i) {
graph[i] = init[i];
}

cout << Dijkstra(graph, 1, 4);
}