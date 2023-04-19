#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max(); // бесконечность

int main() {
    int n, m;
    cin >> n;

    vector<int> cost(n); // стоимость бензина в каждом городе
    for (int i = 0; i < n; i++) 
    {
        cin >> cost[i];
    }

    cin >> m;

    vector<vector<pair<int, int>>> adj(n); // список смежности
    for (int i = 0; i < m; i++) 
    {
        int u, v;
        cin >> u >> v;
        u--, v--; // переход к нумерации с нуля
        adj[u].push_back({v, cost[u]}); // ребро из u в v с весом cost[u]
        adj[v].push_back({u, cost[v]}); // ребро из v в u с весом cost[v]
    }

    vector<int> dist(n, INF); // массив расстояний
    dist[0] = 0; // расстояние от первого города до него самого равно нулю

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // очередь с приоритетом
    pq.push({0, 0}); // первый элемент - расстояние, второй - номер города

    while (!pq.empty()) 
    {
        int u = pq.top().second;
        int w = pq.top().first;
        pq.pop();

        if (w > dist[u]) 
        {
            continue; // оптимизация если уже найдено более короткое расстояние до u, то игнорируем его
        }

        for (auto& edge : adj[u]) 
        {
            int v = edge.first;
            int weight = edge.second;
            if (dist[u] + weight < dist[v]) 
            {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v}); // добавляем v в очередь
            }
        }
    }

    if (dist[n - 1] == INF) 
    {
        cout << "-1\n";
    } 
    else 
    {
        cout << dist[n - 1] << "\n";
    }

    return 0;
}
