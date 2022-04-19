
#include <iostream>
#include <stack>
#include <queue>
#include <string>
#include "Graph.h"

#include "AdjacentMatrixGraph.h"


using namespace std;


void dfs_recursive(int cur_vertex, vector<bool>& visited, Graph* g) {
    visited[cur_vertex] = true;

    vector<int> adj = g->adjacent_vertex(cur_vertex);
    for (auto i : adj) {
        if (!visited[i]) {
            dfs_recursive(i, visited, g);
        }
    }
}

int countConnectedComponents(Graph* g) {
    int countComponents = 0;
    int size = g->vertex_count();
    vector<bool> visited(size, false);

    for (int i = 0; i < size; i++) {
        if (!visited[i]) {
            dfs_recursive(i, visited, g);
            countComponents++;
        }
    }
    return countComponents;
}

int main() {
    /*int size, currentVertex, countEdges; 
    cin >> size >> currentVertex >> countEdges;
    int first, second;

    Graph* g = new AdjacentMatrixGraph(size);
    for (int i = 0; i < countEdges; i++) {
        cin >> first >> second;
        first--;
        second--;
        g->insert(first, second);
    }
    cout << countConnectedComponents(g);*/


    Graph* g = new AdjacentMatrixGraph(5);
    g->insert(0, 1);
    g->insert(1, 2);
    g->insert(0, 2);
    g->insert(3, 4);
    cout << countConnectedComponents(g);


    return 0;
}


