#include <iostream>

using namespace std;

struct PointAndLine
{
    int x;
    int y;
    int a;
    int b;
    int c;

    PointAndLine(int x, int y, int a, int b, int c)
        : x(x), y(y), a(a), b(b), c(c)
    {
    }
};

int main()
{
    int n, w, e;
    cin >> n >> w >> e;

    int a = e - w;
    int b = -100 * n;
    int c = w * 100 * n;
    PointAndLine pointAndLine(0, w, a, b, c);

    int ans = 0;
    for (int i = 1, j = 1; i <= n && j <= n;)
    {
        int x = 100 * i;
        int y = 100 * j;

        PointAndLine p1(x, y, a, b, c);
        PointAndLine p2(x, y - 100, a, b, c);
        PointAndLine p3(x - 100, y, a, b, c);
        PointAndLine p4(x - 100, y - 100, a, b, c);

        int v1 = p1.a * p1.x + p1.b * p1.y + p1.c;
        int v2 = p2.a * p2.x + p2.b * p2.y + p2.c;
        int v3 = p3.a * p3.x + p3.b * p3.y + p3.c;
        int v4 = p4.a * p4.x + p4.b * p4.y + p4.c;

        if (!((v1 > 0 && v2 > 0 && v3 > 0 && v4 > 0) || (v1 < 0 && v2 < 0 && v3 < 0 && v4 < 0)))
        {
            ans++;
        }

        if (j == n)
        {
            i++;
            j = 1;
        }
        else
        {
            j++;
        }
    }
    cout << ans << endl;
    return 0;
}