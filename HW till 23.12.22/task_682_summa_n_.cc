#include <iostream>
#include <string>
using namespace std;

string umn(string a, int n) {
    string c = "";
    int d=0, k;
    for (int z = a.length() - 1; z >= 0; z--)
    {
        k = n * (a[z] - '0')+d;
        c = char(k % 10 + '0') + c;
        d = k / 10;
    }
    if (d>0) c = char(d + '0') + c;
    return c;
}

int main() {
    int n;
    string s="10";
    cin >> n;
    if (n == 1)
    {
        cout << 45;
        return 0;
    }
    for (int i = 1; i < n; i++) s = s + '9';
    s = umn(s, 9);
    s = umn(s, 5);
    for (int i = 2; i < n; i++) s = s + '0';
    cout << s;
    return 0;
}