#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int main() {
    int E, F, N;
    cin >> E >> F >> N;

    vector<int> p(N), w(N);
    for (int i = 0; i < N; i++) {
        cin >> p[i] >> w[i];
    }

    const int INF = INT_MAX / 2;
    vector<int> dp(F - E + 1, INF);
    dp[0] = 0;

    for (int i = 0; i < N; i++) {
        for (int j = w[i]; j <= F - E; j++) {
            dp[j] = min(dp[j], dp[j - w[i]] + p[i]);
        }
    }

    if (dp[F - E] == INF) {
        cout << "This is impossible." << endl;
    } else {
        cout << dp[F - E] << " ";

        dp.assign(F - E + 1, -INF);
        dp[0] = 0;

        for (int i = 0; i < N; i++) {
            for (int j = w[i]; j <= F - E; j++) {
                dp[j] = max(dp[j], dp[j - w[i]] + p[i]);
            }
        }

        cout << dp[F - E] << endl;
    }

    return 0;
}
