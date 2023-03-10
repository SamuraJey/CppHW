#include <iostream>
using namespace std;

int main() {
    int n, s = 0;
    cin >> n;
    int a1 = n / 4;
    if (n < 4)
    {
        cout << 0;
        return 0;
    }
    for (int a = 1; a <= a1; a++)
        for (int b = a; b <= (n-a)/3; b++)
            s = s + (n-a-b)/2-b+1;
    cout << s;
    return 0;
}
