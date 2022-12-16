#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, ost = 0, uk = 1;
    cin >> n;
    int s[303] = { 0 };
    if (n == 0)
    {
    cout << 1; return 0;
    }
    if (n == 1) {
       cout << 2;
       return 0;
    }
    s[0] = 2;
    for (int z = 1; z < n; z++)
    {
       for (int x = 0; x < uk; x++)
       {
           int a = s[x] * 2;
           s[x] = a % 10 + ost;
           ost = a / 10;
       }
       if (ost > 0)
       {
           s[uk] = ost;
           uk++;
           ost = 0;
       }
       }
       for (int z = uk - 1; z >= 0; z--) cout << s[z];
       return 0;
}