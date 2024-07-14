#include "graph.h"

using namespace std;
using namespace std::chrono;

Graph::Graph(int vertices)
{
    this->vertices = vertices;
    adj.resize(vertices);
}

void Graph::addEdge(int vertice, int edge, int peso)
{
    adj[vertice].push_back({edge, peso});
}

void Graph::printGraph()
{
    for (int v = 1; v < vertices; ++v)
    {
        cout << "Vertice " << v << ":";
        for (auto &neighbor : adj[v])
            cout << " -> " << neighbor.first << " (weight: " << neighbor.second << ")";
        cout << endl;
    }
}
int Graph::getVertices()
{
    return vertices;
}

vector<list<pair<int, int>>> Graph::getAdjacents()
{
    return adj;
}
