#include <iostream>
using namespace std;

int main() 
{
    int n, m;
    cin >> n >> m;
    int r = 2 % m;
    for (int i = 0; i < n; i++) r = (r * r) % m;
    cout << r;
    return 0;
}