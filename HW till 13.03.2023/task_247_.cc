#include <iostream>
#include <deque>
#include <cstring>
#include <algorithm>

using namespace std;

const int inf = 1000000;
int dp[105][105];
int a[105];

int DP(int i, int j) {
    if (j > i) return inf;
    else {
        int res;
        int cost = a[i];
        if (j <= 0) {
            if (i >= 1) {
                if (cost <= 100) {
                    int dif = min(DP(i - 1, j + 1), DP(i - 1, j) + cost);
                    res = dif;
                } else {
                    return DP(i - 1, j + 1);
                }
            } else return 0;
        } else {
            if (dp[i][j] != -1) return dp[i][j];
            if (cost > 100) {
                int dif = min(DP(i - 1, j + 1), DP(i - 1, j - 1) + cost);
                res = dif;
            } else {
                int dif = min(DP(i - 1, j + 1), DP(i - 1, j) + cost);
                res = dif;
            }
        }
        dp[i][j] = res;
        return res;
    }
}

void GOODOLDDAYS(deque<int>& used, int i, int j) {
    if (j < i) {
        int cost = a[i];
        if (j <= 0) {
            if (i >= 1) {
                if (cost > 100) {
                    used.push_back(i);
                    GOODOLDDAYS(used, i - 1, j + 1);
                } else {
                    bool addi = (DP(i, j) == DP(i - 1, j + 1));
                    if (addi) {
                        used.push_back(i);
                        GOODOLDDAYS(used, i - 1, j + 1);
                    } else GOODOLDDAYS(used, i - 1, j);
                }
            }
        } else {
            if (cost <= 100) {
                bool addi = (DP(i - 1, j + 1) == DP(i, j));
                if (addi) {
                    used.push_back(i);
                    GOODOLDDAYS(used, i - 1, j + 1);
                } else {
                    GOODOLDDAYS(used, i - 1, j);
                }
            } else {
                bool addi = (DP(i - 1, j + 1) == DP(i, j));
                if (addi) {
                    used.push_back(i);
                    GOODOLDDAYS(used, i - 1, j + 1);
                } else {
                    GOODOLDDAYS(used, i - 1, j - 1);
                }
            }
        }
    }
}

int main() {
    int n;
    cin >> n;

    int k1 = 0, k2 = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    memset(dp, -1, sizeof(dp));

    int ans = inf;

    for (int i = 0; i <= n; i++) {
        if (ans >= DP(n, i)) {
            ans = DP(n, i);
            k1 = i;
        }
    }

    cout << ans << endl;

    deque<int> used;
    GOODOLDDAYS(used, n, k1);
    k2 = used.size();
    cout << k1 << " " << k2 << endl;
    
    
    return 0;
}