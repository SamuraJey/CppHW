#include <bits/stdc++.h>
using namespace std;
typedef vector<char> H;
typedef vector<H> V;
typedef int D;
#define S(a) a.size()
#define J return
#define F(i, c, j) for (i; c; j++)

V R()
{
    D p, f;
    cin >> p >> f;
    V a(p, H(f));
    F(D i = 0, i < p, i)
    F(D j = 0, j < f, j)
    cin >> a[i][j];
    J a;
}

V d(V a)
{
    D p = S(a), f = S(a[0]);
    V r(f, H(p));

    F(D i = 0, i < p, i)
    F(D k = 0, k < f, k)
    r[k][i] = a[i][k];
    J r;
}

V h(V a)
{
    D p = S(a), f = S(a[0]);
    V r(p, H(f));

    F(D i = 0, i < p, i)
    F(D j = 0, j < f, j)
    r[p - 1 - i][j] = a[i][j];
    J r;
}

V R(V a)
{
    D p = S(a), f = S(a[0]);
    D s = p, z = -1, q = f, l = -1;

    F(D i = 0, i < p, i)
    F(D j = 0, j < f, j)
    if (a[i][j] == '#')
    {
        s = min(s, i);
        q = min(q, j);
        z = max(z, i);
        l = max(l, j);
    }
    if (z == -1)
        J V();
    V r(z - s + 1, H(l - q + 1));
    F(D i = s, i <= z, i)
    F(D j = q, j <= l, j)
    r[i - s][j - q] = a[i][j];
    J r;
}

V T(V a)
{
    J h(d(a));
}

main()
{
    V a = R(R()), b = R(R());
    F(D i = 0, i < 2, i)
    {
        a = h(a);
        F(D j = 0, j < 4, j)
        {
            a = T(a);
            if (a == b)
            {
                cout << "Yes";
                J 0;
            }
        }
    }
    cout << "No";
}