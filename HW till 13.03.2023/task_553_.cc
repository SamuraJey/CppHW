#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    vector<int> leftPar(1 + n);
    vector<int> rightPar(1 + n);

    for (size_t i = 1; i <= n; i++)
    {
        scanf("%d %d", &leftPar[i], &rightPar[i]);
    }

    vector<vector<int>> cost(1 + n, vector<int>(1 + n));

for (size_t len = 1; len <= n; len++)
{
    for (size_t left = 1; left + len - 1 <= n; left++)
    {
        int right = left + len - 1;
        if (len == 1)
        {
            cost[left][right] = 0;
        }
        else
        {
            int minimal = 1000 * 1000 * 1000;
            for (size_t right1 = left; right1 < right; right1++)
            {
                int left2 = right1 + 1;
                minimal = min(minimal, (cost[left][right1] + cost[left2][right]));
            }
            cost[left][right] = minimal + leftPar[left] * rightPar[right];
        }
    }
}
    printf("%d", cost[1][n]);
    return 0;
}