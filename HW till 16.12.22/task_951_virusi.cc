#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector <int> arr1(k);
    vector <int> arr2(k);

    int min, max;

    for (int i = 0; i < k; i++) cin >> arr1[i] >> arr2[i];
    max = 0;
    for (int i=0; i<n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            min = n + m;
            for (int z = 0; z < k; z++)
            {
                int d = abs(i - arr1[z]+1) + abs(j - arr2[z]+1);
                if (min > d) min = d;
            }
            if (min > max)
            {
                max = min;
            }
        }
    }

    cout << max;
    return 0;
}