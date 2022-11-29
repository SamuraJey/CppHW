#include <iostream>

using namespace std;

int main()
{
    unsigned int n, m, k, d, l;
    cin >> n >> m >> k >> d;

    if ((k * m * n - k * m - m * n - n * k) > 0)
    {
        l = d * k * m * n / (k * m * n - k * m - m * n - n * k);
    }
    else
    {
        cout << -1; 
        return 0; 
    }

    if (l > 0 && l % k == 0 && l % m == 0 && l % n == 0 && l / k + l / m + l / n + d == l)
    {
        cout << l;
    }
    else
    {
        cout << -1;
    }

    return 0;
}