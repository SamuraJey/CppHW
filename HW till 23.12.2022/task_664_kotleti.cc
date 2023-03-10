#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
    double k, m, n;
    cin >> k >> m >> n;
    if (n <= k) cout << 2 * m; else
    cout << ceil((2 * n) / k) * m;
    return 0;
}