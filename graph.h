//
// Created by Fawzy on 12/12/2023.
//

#ifndef UNTITLED2_GRAPH_H
#define UNTITLED2_GRAPH_H
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <queue>
#include <climits>
#include <stack>
#include <map>
#include <string>
using namespace std;

class Graph {

private:
    string filename = "assign 6 applied";
public:

    vector<vector<int>> graph;

    Graph() {

        filename = "C:/Users/Fawzy/OneDrive - YAT learning Solutions/Desktop/assign 6 applied.txt";
        graph = readAdjacencyMatrix(filename);
    }
    map<int, char> intToLetterMap;


    vector<vector<int>> readAdjacencyMatrix(const string &filename);

    void dfs2(int v, vector<bool> &visited, const vector<vector<int>> &graph);

    void dfs(const vector<vector<int>> &graph, int start);

    void dijkstra(const vector<vector<int>> &graph, int src, vector<int> &prev, vector<int> &dist);

    void printAdjacencyMatrix(const vector<vector<int>> &graph);

    void printGraphEdges(const vector<vector<int>> &graph);

    void printShortestPaths(const vector<int> &prev, int src);

    void setIntToLetterMap(map<int, char> &map, const vector<vector<int>> &graph);


};


#endif //UNTITLED2_GRAPH_H
