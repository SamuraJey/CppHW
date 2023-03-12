#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int m, n;
    cin >> m >> n;

    double fraction = (double)m / n;
    vector<int> result;

    for (int i = 2; i <= n; i++) 
    {
        if (fraction == 0)
        {
            break;
        }
        if (fraction >= 1.0 / i)
        {
            result.push_back(i);
            fraction -= 1.0 / i;
        }
    }

    for (int i = 0; i < result.size(); i++) 
    {
        cout << result[i] << " ";
    }

    return 0;
}
