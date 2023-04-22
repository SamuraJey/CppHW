#include <bits/stdc++.h>




//#define endl        '\n'
//#define 1000000007        1000000007
#define rep(i,a,b)  for(int i=a;i<b;i++)
using namespace std;


vector<int> parent;
vector<int> rnk;

int get_parent(int v)
{
    if (v == parent[v])
        return v;
    return parent[v] = get_parent(parent[v]);
}

void merge_set(int a, int b)
{
    a = get_parent(a);
    b = get_parent(b);

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

void initialize(int n)
{
    parent.resize(n + 1);
    rnk.resize(n + 1);

    for (int i = 1; i <= n; i++)
    {
        parent[i] = i;
        rnk[i] = 0;
    }
}


void solve()
{
    int n, d, a;
    cin >> n >> d >> a;
    vector<string> g(n);

    initialize(n);

    for (int i = 0; i < n; i++)
    {
        cin >> g[i];
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
            if (g[i][j] == '1' and added.find({i, j}) == added.end() and added.find({j, i}) == added.end())
            {
                added[ {i, j}] = true;

                if (get_parent(i + 1) != get_parent(j + 1))
                {
                    merge_set(i + 1, j + 1);
                }
                else
                {
                    // cancel the flight...
                    ans += d;
                    g_ans[i][j] = 'd';
                    g_ans[j][i] = 'd';
                }
            }
        }
    }

    // rep(i, 0, n)
    // {
    //     rep(j, 0, sz(g[i]))
    //     {
    //         if (g[i][j] == '1' and added.find({i, j}) == added.end() and added.find({j, i}) == added.end())
    //         {
    //             added[ {i, j}] = true;

    //             if (get_parent(i + 1) != get_parent(j + 1))
    //             {
    //                 merge_set(i + 1, j + 1);
    //             }
    //             else
    //             {
    //                 // cancel the flight...
    //                 ans += d;
    //                 g_ans[i][j] = 'd';
    //                 g_ans[j][i] = 'd';
    //             }
    //         }
    //     }
    // }

    vector<int> vis(n + 1, -1);
    vector<int> rem;

    rep(i, 1, n + 1)
    {
        vis[get_parent(i)] = 1;
    }

    rep(i, 1, n + 1)
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
}


int main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    // cout.tie(0);
    int t = 1;
    // cin>>t;
    solve();
    // while (t--)
    // {
    //     solve();
    // }
    return 0;
}
