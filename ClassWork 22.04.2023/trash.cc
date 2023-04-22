#include <bits/stdc++.h>

using namespace std;

int get_parent(int idx, vector<int> &parent)
{
    if (idx == parent[idx])
    {
        return idx;
    }
    return parent[idx] = get_parent(parent[idx], parent);
}

void merge_set(int a, int b, vector<int> &parent, vector<int> &rnk)
{
    a = get_parent(a, parent);
    b = get_parent(b, parent);
    if (a != b)
    {
        if (rnk[a] < rnk[b])
        {
            swap(a, b);
        }
        parent[b] = a;
        if (rnk[a] == rnk[b])
        {
            rnk[a]++;
        }
    }
}

void initialize(int n, vector<int> &parent, vector<int> &rnk)
{
    parent.resize(n + 1);
    rnk.resize(n + 1);
    for (int i = 1; i <= n; i++)
    {
        parent[i] = i;
        rnk[i] = 0;
    }
}

int main()
{
    vector <int> parent;
    vector <int> rnk;
    int n, d, a;
    cin >> n >> d >> a;
    vector <string> inpArr(n);
    initialize(n, parent, rnk);
    
    for (int i = 0; i < n; i++)
    {
        cin >> inpArr[i];
    }

    map<pair<int, int>, bool> added;

    vector<string> g_ans(n);

    for (int i = 0; i < n; i++)
    {
        g_ans[i] = string(n, '0');
    }
    long long ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (inpArr[i][j] == '1' and added.find({i, j}) == added.end() and added.find({j, i}) == added.end())
            {
                added[ {i, j}] = true;
                if (get_parent(i + 1, parent) != get_parent(j + 1, parent))
                {
                    merge_set(i + 1, j + 1, parent, rnk);
                }
                else
                {
                    // cancel the flight
                    ans += d;
                    g_ans[i][j] = 'd';
                    g_ans[j][i] = 'd';
                }
            }
        }
    }
    vector<int> vis(n + 1, -1);
    vector<int> rem;

    for (int i = 1; i <= n; i++)
    {
        vis[get_parent(i, parent)] = 1;
    }
    // rep(i, 1, n + 1)
    // {
    //     vis[get_parent(i)] = 1;
    // }

    for (int i = 1; i <= n; i++)
    {
        if (vis[i] != -1)
        {
            rem.push_back(i);
        }
    }
    for (int i = 1; i < rem.size(); i++)
    {
        g_ans[rem[0] - 1][rem[i] - 1] = 'a';
        g_ans[rem[i] - 1][rem[0] - 1] = 'a';
        ans += a;
    }
    cout << ans << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << g_ans[i][j];
        }
        cout << endl;
    }
    return 0;
}
