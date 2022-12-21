#include <iostream>
#include <string>

using namespace std;

int main() {
    string s, a="", b;
    cin >> s;
    int n;
    cin >> n;
    if (n > 0) 
    {
        int z = 0;
        while (z<n && a.length() < 1023) {
            a = a + s; z++;
        }
        if (a.length() > 1023) cout << a.substr(0, 1023);
        else cout << a;
    }
    else
    {
        if (s.length() % (-n) == 0)
        {
            b = s.substr(0, s.length() / (-n));
            for (int z = 0; z < (-n); z++)
            {
                a = a + b;
            }
            if (a == s)
            {
                cout << b;
            }
            else cout << "NO SOLUTION";
        }
        else cout << "NO SOLUTION";
    }
    return 0;
}