#include <iostream>

struct Point
{
    int x;
    int y;

    Point(int x, int y)
        : x(x), y(y)
    {
    }
};

struct Line
{
    int a;
    int b;
    int c;

    Line(const Point &p1, const Point &p2)
        : a(p2.y - p1.y), b(p1.x - p2.x), c(p2.x * p1.y - p1.x * p2.y)
    {
    }

    int apply(const Point &p) const
    {
        int res = a * p.x + b * p.y + c;
        return res;
    }
};

int main()
{
    int n, w, e;
    std::cin >> n >> w >> e;
    Line line(Point{0, w}, Point{100 * n, e});
    int ans = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            Point p1{100 * i, 100 * j};
            Point p2{100 * i, 100 * j - 100};
            Point p3{100 * i - 100, 100 * j};
            Point p4{100 * i - 100, 100 * j - 100};
            int v1 = line.apply(p1);
            int v2 = line.apply(p2);
            int v3 = line.apply(p3);
            int v4 = line.apply(p4);
            if (!((v1 > 0 && v2 > 0 && v3 > 0 && v4 > 0) || (v1 < 0 && v2 < 0 && v3 < 0 && v4 < 0)))
            {
                ans++;
            }
        }
    }
    std::cout << ans << std::endl;
    return 0;
}
