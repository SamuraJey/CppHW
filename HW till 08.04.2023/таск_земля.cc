#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int H, W, N;
    cin >> H >> W >> N;

    vector<int> cost(H*W);
    for(int i=0; i<H*W; i++) {
        cin >> cost[i];
    }

    vector<int> sum((H+1)*(W+1));
    for(int i=1; i<=H; i++) {
        for(int j=1; j<=W; j++) {
            sum[i*(W+1)+j] = cost[(i-1)*W+(j-1)] + sum[(i-1)*(W+1)+j] + sum[i*(W+1)+j-1] - sum[(i-1)*(W+1)+j-1];
        }
    }

    for(int i=0; i<N; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        int total_cost = sum[c*(W+1)+d];
        if(b > 1) {
            total_cost -= sum[c*(W+1)+b-1];
        }
            if(a > 1) {
        total_cost -= sum[(a-1)*(W+1)+d];
    }
    if(a > 1 && b > 1) {
        total_cost += sum[(a-1)*(W+1)+b-1];
    }
    cout << total_cost << endl;
}

return 0;
}
