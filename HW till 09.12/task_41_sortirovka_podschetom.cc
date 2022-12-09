#include<bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    int n, k;
    cin >> n;
    vector <int> arr;

    for (int i = 0; i < n; i++)
    {
        cin >> k;
        arr.push_back(k);
    }

    sort(arr.begin(), arr.end());

    for (auto j : arr)
    {
        cout << j << " ";
    }
    
    return 0;
}




