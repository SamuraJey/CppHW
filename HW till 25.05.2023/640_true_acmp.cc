#include <bits/stdc++.h>
using namespace std;
#define H vector<char>
#define V vector<H>
#define D int
#define S(a) a.size()
#define J return
#define F(i, c, j) for (D i=0; c ; j++)
#define P a[i][j]

V R()
{
    D p, f;
    cin >> p >> f;
    V a(p, H(f));
    F(i, i < p, i)
    F(j, j < f, j)
    cin >> P;
    J a;
}

V d(V a)
{
    D p = S(a), f = S(a[0]);
    V r(f, H(p));

    F(i, i < p, i)
    F(j, j < f, j)
    r[j][i] = P;
    J r;
}

V h(V a)
{
    D p = S(a), f = S(a[0]);
    V r(p, H(f));

    F(i, i < p, i)
    F(j, j < f, j)
    r[p - 1 - i][j] = P;
    J r;
}

V R(V a)
{
    D p = S(a), f = S(a[0]);
    D s = p, z = -1, q = f, l = -1;

    F(i, i < p, i)
    F(j, j < f, j)
    if (P == '#')
    {
        s = min(s, i);
        q = min(q, j);
        z = max(z, i);
        l = max(l, j);
    }
    if (z == -1)
        J V();
    V r(z - s + 1, H(l - q + 1));
    for (D i = s; i <= z; i++)
    for(D j = q; j <= l; j++)
    r[i - s][j - q] = P;
    J r;
}

V T(V a)
{
    J h(d(a));
}

main()
{
    V a = R(R()), b = R(R());
    F(i, i < 2, i)
    {
        a = h(a);
        F(j, j < 4, j)
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