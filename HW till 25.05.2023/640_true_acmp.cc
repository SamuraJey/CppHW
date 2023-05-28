#include <bits/stdc++.h>
using namespace std;
#define H vector<char>
#define V vector<H>
#define D int
#define S(a) a.size()
#define J return
#define F(i, c, l) for (D i=0; i < c ; i++) {l}
#define P a[i][j]

V R()
{
    D p, f;
    cin >> p >> f;
    V a(p, H(f));
    F(i, p, F(j, f, cin >> P;))
    J a;
}

V d(V a)
{
    D p = S(a), f = S(a[0]);
    V r(f, H(p));
    F(i, p, F(j, f, r[j][i] = P;))
    J r;
}

V h(V a)
{
    D p = S(a), f = S(a[0]);
    V r(p, H(f));
    F(i, p, F(j, f, r[p - 1 - i][j] = P;))
    J r;
}

V R(V a)
{
    D p = S(a), f = S(a[0]), s = p, z = -1, q = f, l = -1;

    F(i, p, F(j, f, if (P == '#'){(s = min(s, i), q = min(q, j), z = max(z, i), l = max(l, j));}))
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
    F(i, 2, a = h(a);F(j, 4, a = T(a);if (a == b){cout << "Yes";J 0;}))
    cout << "No";
}