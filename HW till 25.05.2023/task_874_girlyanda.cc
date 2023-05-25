#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 8;
const int MAXM = 10;

int n, k, m;

bool isValidColor(int u, int c, vector<vector<int>> &adj, vector<int> &colors)
{
    for (int i = 0; i < adj[u].size(); i++)
    {
        int v = adj[u][i];
        if (colors[v] == c)
        {
            return false;
        }
    }
    return true;
}

int countValidColorings(int currentVertex, vector<vector<int>> &adj, vector<int> &colors)
{
    if (currentVertex > n)
    {
        return 1;
    }
    int count = 0;
    for (int c = 1; c <= k; c++)
    {
        if (isValidColor(currentVertex, c, adj, colors))
        {
            colors[currentVertex] = c;
            count += countValidColorings(currentVertex + 1, adj, colors);
            colors[currentVertex] = 0;
        }
    }
    return count;
}

int main()
{
    vector<vector<int>> adj(MAXN + 1);
    vector<int> colors(MAXN + 1);

    cin >> n >> k >> m;

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    colors.assign(n + 1, 0);
    int ans = countValidColorings(1, adj, colors);

    cout << ans << endl;

    return 0;
}