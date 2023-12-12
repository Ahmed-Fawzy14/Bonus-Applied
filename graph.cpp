//
// Created by Fawzy on 12/12/2023.
//

#include "graph.h"

vector<vector<int>> Graph::readAdjacencyMatrix(const string &filename) {
    vector<vector<int>> matrix;
    ifstream file(filename);
    string line, cell;

    getline(file, line);

    while (getline(file, line)) {
        stringstream lineStream(line);
        vector<int> row;

        getline(lineStream, cell, '\t');

        while (getline(lineStream, cell, '\t')) {
            if (cell == "0" || cell.empty()) {
                row.push_back(INT_MAX);
            } else {
                row.push_back(stoi(cell));
            }
        }
        matrix.push_back(row);
    }

    return matrix;
}

void  Graph::dfs2(int v, vector<bool>& visited, const vector<vector<int>>& graph) {
    visited[v] = true;
    cout << v << " ";

    for (int i = 0; i < graph[v].size(); i++) {
        if (graph[v][i] != 0 && !visited[i]) {
            dfs2(i, visited, graph);
        }
    }
}

void  Graph::dfs(const vector<vector<int>>& graph, int start) {
    vector<bool> visited(graph.size(), false);
    dfs2(start, visited, graph);
}


void  Graph::dijkstra(const vector<vector<int>>& graph, int src, vector<int> &prev, vector<int> &dist) {

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    dist[src] = 0;
    pq.push(make_pair(0, src));

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        for (int v = 0; v < graph.size(); v++) {
            if (graph[u][v] != INT_MAX && dist[u] != INT_MAX && dist[v] > dist[u] + graph[u][v]) {
                dist[v] = dist[u] + graph[u][v];
                prev[v] = u;
                pq.push(make_pair(dist[v], v));
            }
        }
    }

}

void  Graph::printAdjacencyMatrix(const vector<vector<int>>& graph) {
    cout << "\n Adjacency Matrix" << endl;
    for (const auto& row : graph) {
        for (int weight : row) {
            cout << (weight == INT_MAX ? 0 : weight) << "  ";
        }
        cout << endl;
    }
}

void  Graph::printGraphEdges(const vector<vector<int>>& graph) {
    cout << "\n Graph Edges" << endl;
    for (int i = 0; i < graph.size(); i++) {
        for (int j = 0; j < i; j++) {
            if (graph[i][j] != INT_MAX) {
                cout << char('A' + i) << " " << char('A' + j) << " " << graph[i][j] << endl;
            }
        }
    }
}

void  Graph::printShortestPaths(const vector<int>& prev, int src) {
    cout << "\n Shortest Paths from Node: " << char('A' + src) << endl;
    for (int i = 0; i < prev.size(); i++) {
        stack<int> path;
        int at = i;
        cout << "  ";
        while (at != -1) {
            path.push(at);
            at = prev[at];
        }

        while (!path.empty()) {
            //cast to from int to char
            cout << char('A' + path.top());
            path.pop();
            if (!path.empty()) {
                cout << " -> ";
            }
        }
        cout << endl;
    }
}

void  Graph::setIntToLetterMap(map<int, char> &map, const vector<vector<int>>& graph)
{
    for(int i = 0; i < graph.size(); i++)
    {

        map.insert(make_pair(i, char(65+i)));

    }
}

