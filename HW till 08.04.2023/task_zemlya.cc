#include <iostream>
#include <vector>
using namespace std;

int main() {
    int H, W, N;
    scanf("%d%d%d", &H, &W, &N);

    vector<vector<int>> cost(H, vector<int>(W));
    for(int i=0; i<H; i++) {
        for(int j=0; j<W; j++) {
            cin >> cost[i][j];
        }
    }

    vector<vector<int>> sum(H+1, vector<int>(W+1));
    for(int i=1; i<=H; i++) {
    int row_sum = 0;
    for(int j=1; j<=W; j++) {
        row_sum += cost[i-1][j-1];
        sum[i][j] = row_sum + sum[i-1][j];
    }
}


    for(int i=0; i<N; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        int total_cost = sum[c][d];
        if(b > 1) {
            total_cost -= sum[c][b-1];
        }
        if(a > 1) {
            total_cost -= sum[a-1][d];
        }
        if(a > 1 && b > 1) {
            total_cost += sum[a-1][b-1];
        }
        cout << total_cost << endl;
    }

    return 0;
}
