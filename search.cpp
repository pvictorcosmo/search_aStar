#include "search.h"
#include <vector>
#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <unordered_map>
#include <algorithm>
#include <limits>

using namespace std;

vector<int> Search::search_aStar(int start, int goal, int vertices, vector<list<pair<int, int>>> adj)
{
    // Vetor de distâncias mínimas
    vector<int> dist(vertices, numeric_limits<int>::max());

    // Fila de prioridade (menor distância primeiro)
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    // Mapa de pais para reconstruir o caminho
    unordered_map<int, int> parent;

    // Inicialização do algoritmo
    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();

        if (u == goal)
            break;

        for (auto &neighbor : adj[u])
        {
            int v = neighbor.first;
            int weight = neighbor.second;

            int newDist = dist[u] + weight;

            if (newDist < dist[v])
            {
                dist[v] = newDist;
                parent[v] = u;
                pq.push({newDist, v});
            }
        }
    }

    // Reconstrói o caminho a partir do goal até o start
    vector<int> path;
    for (int v = goal; v != start; v = parent[v])
        path.push_back(v);
    path.push_back(start);

    reverse(path.begin(), path.end());

    return path;
}
