#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n,k;
    int m = 0;
    cin >> n >> k;
    vector <int> a(n);
    
    for (int z = 0; z < n; z++)
    {
        a[z] = z + 1;
    }
    while (a.size() > 1)
    {
        m += k - 1;
        m = m % a.size();
        a.erase(a.begin() + m);
    }

    cout << a[0];
    return 0;
}
