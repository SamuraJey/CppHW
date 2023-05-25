#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <utility>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

struct edge
{
    int from, to, start_time, end_time;
    edge(int from, int to, int start_time, int end_time)
        : from(from), to(to), start_time(start_time), end_time(end_time){};
};

const int INF = numeric_limits<int>::max();

int main()
{
    int n, m, s, t;
    int x, y, start_time, end_time;
    vector<edge> edges;

    cin >> n >> s >> t >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> x >> start_time >> y >> end_time;

        edges.push_back(edge(x, y, start_time, end_time));
    }
    vector<int> d(n + 1, INF);
    d[s] = 0;
    while (true)
    {
        bool ok = false;
        for (int i = 0; i < m; i++)
        {
            if (d[edges[i].from] < INF && d[edges[i].from] <= edges[i].start_time && edges[i].end_time < d[edges[i].to])
            {
                d[edges[i].to] = edges[i].end_time;
                ok = true;
            }
        }
        if (!ok)
        {
            break;
        }
    }
    cout << (d[t] < INF ? d[t] : -1);
    return 0;
}