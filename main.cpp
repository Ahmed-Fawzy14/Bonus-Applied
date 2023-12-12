

using namespace std;
#include "graph.h"


//material used:
//https://www.geeksforgeeks.org/implementation-of-dfs-using-adjacency-matrix/
//https://www.geeksforgeeks.org/dijkstras-shortest-path-algorithm-greedy-algo-7/
int main() {

    Graph g;




    g.printAdjacencyMatrix(g.graph);
    g.printGraphEdges(g.graph);

    int V = g.graph.size();
    vector<int> dist(V, INT_MAX);
    vector<int> prev(V, -1);
    char choice = 'F';


    g.setIntToLetterMap(g.intToLetterMap, g.graph);

    cout << "Number of Vertices: " << g.graph.size() << endl;

    int edgeCount = 0;
    for (const auto& row : g.graph) {
        for (int weight : row) {
            if (weight != INT_MAX && weight != 0) {
                edgeCount++;
            }
        }
    }
    cout << "Number of Edges: " << edgeCount / 2 << endl;


    do{
        cout << "Choose the source node (A,B,C,etc..): " << endl;
        cin >> choice;

        if (choice >= 'A' && choice <= 'Z') {
            int src = choice - 'A'; // Convert char to index
            g.dijkstra(g.graph, src, prev, dist);
            g.printShortestPaths(prev, src);
        } else {
            cout << "Invalid input" << endl;
        }
        if(choice == ' ')
            cout<<"Enter a choice"<<endl;
        else
        {
            g.dijkstra(g.graph, g.intToLetterMap[choice-65], prev, dist);
            g.printShortestPaths(prev, g.intToLetterMap[choice-65]);
        }
    }while(choice == ' ');





    return 0;
}
