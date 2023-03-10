#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int m, i, k,p;
    m = 500000;
    k = 2;
    vector <int> f;
    f.push_back(2);
    f.push_back(3);
    i = 5;
    p = 1;
    while (i < m)
    {
        bool flag = 1;
        for (int j = 0; j<k; j++)
        {
            if (f[j] * f[j]>i) break;  // является простым
            if (i%f[j] == 0) flag = 0;    // не является простым
        }
        if (flag) {
            f.push_back(i);
            k++;
        }
        if (i == p * 6 - 1) { i = p * 6 + 1; p++; }
        else i = p * 6 - 1;
    }

    // Работаем
    int s;
    while (cin >> s) {
            int b=s,a=0;
            while (b > 0) { // сумма цифр числа
                a += b % 10; b = b / 10;
            }
            b = s;
            int b1 = b, last=0,lastv;
            int c = 0; // сумма цифр простых множителей
            while (b > 1) {
                for (int z = 0;  b>1 && z < f.size(); z++) {
                        if (z==f.size()-1) { b = 1; break; } // это не составное число
                        lastv = 0;
                        if (b1 == f[z]) { b = 1; break; } // это не составное число
                        while (b%f[z] == 0) {
                                int v = f[z];
                                if (v == last) { c += lastv; }
                                else {
                                    while (v > 0) { lastv += v % 10; v = v / 10; }
                                    c += lastv;
                                }
                                last = f[z];
                                b /= f[z];
                        }
                }
                if (a == c) cout << 1; else cout << 0;
                c = 0;
        }
    }
    return 0;
}