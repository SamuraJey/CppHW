#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() 
{
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) 
    {
        cin >> a[i];
    }

    vector<vector<int>> dp(n, vector<int>(n));
    for (int len = 3; len <= n; len++) {
        for (int i = 0; i + len - 1 < n; i++) 
        {
            int j = i + len - 1;
            dp[i][j] = 1e9;
            for (int k = j - 1; k > i; k--) 
            {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j] + a[k] * (a[i] + a[j]));
            }
        }
    }

    cout << dp[0][n-1] << endl;

    return 0;
}
