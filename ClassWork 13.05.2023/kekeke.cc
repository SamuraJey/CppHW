#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

struct Edge {
    int destination;
    int cost;
    int index;

    Edge(int dest, int c, int idx) : destination(dest), cost(c), index(idx) {}
};

typedef vector<vector<Edge>> Graph;

pair<int, vector<int>> findMinimumCostPath(const Graph& graph, int start, int numCities) {
    vector<int> cost(numCities + 1, numeric_limits<int>::max());
    vector<int> prev(numCities + 1, -1);
    vector<int> channelUsed;
    cost[start] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push(make_pair(0, start));

    while (!pq.empty()) {
        int currentCity = pq.top().second;
        int currentCost = pq.top().first;
        pq.pop();

        if (currentCost > cost[currentCity]) {
            continue;
        }

        for (const Edge& edge : graph[currentCity]) {
            int nextCity = edge.destination;
            int newCost = currentCost + edge.cost;

            if (newCost < cost[nextCity]) {
                cost[nextCity] = newCost;
                prev[nextCity] = edge.index;
                pq.push(make_pair(newCost, nextCity));
            }
        }
    }

    int totalCost = 0;
    for (int c : cost) {
        if (c != numeric_limits<int>::max()) {
            totalCost += c;
        }
    }

    for (int i = 1; i <= numCities; i++) {
        if (prev[i] != -1) {
            channelUsed.push_back(prev[i]);
        }
    }

    return make_pair(totalCost, channelUsed);
}

int main() {
    int numCities, numChannels;
    cin >> numCities >> numChannels;

    Graph graph(numCities + 1);

    for (int i = 0; i < numChannels; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        graph[u].push_back(Edge(v, c, i + 1));
    }

    pair<int, vector<int>> result = findMinimumCostPath(graph, 1, numCities);

    cout << result.first << " " << result.second.size() << endl;
    for (int c : result.second) {
        cout << c << " ";
    }
    cout << endl;

    return 0;
}
