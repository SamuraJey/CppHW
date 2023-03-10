#include <iostream>
using namespace std;

int main() {
    long long n;
    cin >> n;

    while (n % 5 == 0)
    {
        n /= 5;
    }
    while (n % 2 == 0)
    {
        n /= 2;
    }
    if (n > 1)
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }
    
    return 0;
}