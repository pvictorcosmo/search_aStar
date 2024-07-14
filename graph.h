#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <unordered_map>
#include <algorithm>
#include <limits>
#include <chrono> // Biblioteca para medição de tempo

using namespace std;
using namespace std::chrono;

class Graph
{
private:
    int vertices;
    vector<list<pair<int, int>>> adj;

public:
    Graph(int vertices);

    void addEdge(int vertice, int edge, int peso);

    void printGraph();

    int getVertices();

    vector<list<pair<int, int>>> getAdjacents();
};

#endif // GRAPH_H
