#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct Edge
{
    int u, v, w, id;
    bool operator<(const Edge &other) const
    {
        return w < other.w;
    }
};

const int MAXN = 22;
const int MAXM = 22;

int n, m;
Edge edges[MAXM];
int parent[MAXN];
int rankk[MAXN];

int find(int u)
{
    if (parent[u] == u)
    {
        return u;
    }
    return parent[u] = find(parent[u]);
}

void unite(int u, int v)
{
    u = find(u);
    v = find(v);
    if (u != v)
    {
        if (rankk[u] < rankk[v])
        {
            swap(u, v);
        }
        parent[v] = u;
        if (rankk[u] == rankk[v])
        {
            rankk[u]++;
        }
    }
}

int main()
{
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
        edges[i].id = i + 1;
    }

    sort(edges, edges + m);

    for (int i = 1; i <= n; i++)
    {
        parent[i] = i;
        rankk[i] = 0;
    }

    vector<int> tree_edges;
    int tree_cost = 0;

    // добавляем все ребра, выходящие из вершины номер 1
    for (int i = 0; i < m; i++)
    {
        if (edges[i].u == 1)
        {
            tree_edges.push_back(edges[i].id);
            tree_cost += edges[i].w;
            unite(edges[i].u, edges[i].v);
        }
    }

    // продолжаем добавлять рёбра по алгоритму Крускала
    for (int i = 0; i < m; i++)
    {
        int u = edges[i].u;
        int v = edges[i].v;
        int w = edges[i].w;
        if (find(u) != find(v))
        {
            unite(u, v);
            tree_edges.push_back(edges[i].id);
            tree_cost += w;
        }
    }

    cout << tree_cost << " " << tree_edges.size() << endl;
    for (int i = 0; i < tree_edges.size(); i++)
    {
        cout << tree_edges[i] << " ";
    }
    cout << endl;

    return 0;
}