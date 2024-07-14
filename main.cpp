

#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <unordered_map>
#include <algorithm>
#include <limits>
#include <chrono>
#include "graph.h"
#include "search.h"

using namespace std::chrono;

int main()
{

    Graph g(1000);

    srand(time(NULL));
    const int num_edges = 5000;
    for (int i = 0; i < num_edges; ++i)
    {
        int u = rand() % 1000;
        int v = rand() % 1000;
        int weight = rand() % 10 + 1;
        g.addEdge(u, v, weight);
    }

    int start = 0;
    int goal = 999;

    auto start_time = high_resolution_clock::now();
    vector<int> path = Search::search_aStar(start, goal, g.getVertices(), g.getAdjacents());
    auto end_time = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>(end_time - start_time);

    cout << "Caminho minimo de " << start << " a " << goal << " usando A*:" << endl;
    for (int i = 0; i < path.size(); ++i)
    {
        cout << path[i];
        if (i < path.size() - 1)
            cout << " -> ";
    }
    cout << endl;

    cout << "Tempo: " << duration.count() << " microseconds" << endl;

    return 0;
}
