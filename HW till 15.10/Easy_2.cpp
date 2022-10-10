#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int n, k;
    long res = 0;

    cout << "Enter n: ";
    cin >> n;

    cout << "Enter k: ";
    cin >> k;

    for (int i = 1; i < n + 1; i++)
    {
        res += pow(i, k);
    }

    cout << "" << endl;
    cout << "Result: " << res << endl;
}