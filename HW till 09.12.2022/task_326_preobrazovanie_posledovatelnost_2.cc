#include<bits/stdc++.h>

using namespace std;


int main() {
    int n;
    cin >> n;
    vector <int> a(n);
    int b[201] = { 0 };
    
    for (int z = 0; z < n; z++)
    {
        cin >> a[z];
        b[a[z]+100]++; // подсчитываем числа. добавляем 100 чтоб был "модуль", 
    }
    int maxn = -101, maxnn=0;

    for (int z = 0; z < 201; z++)
    {
        if (b[z] > maxn)
        {
            maxn = b[z]; 
            maxnn = z;
        } // ищем самые частые
    }
    for (int z = 0; z < n; z++)
    {
        if (a[z] != maxnn-100) 
        {
            cout << a[z] << " ";
        }
    }
    for (int z = 0; z < maxn; z++)
    {
        cout << maxnn - 100 << " ";
    }
    // выводим сначала часто повторяющиеся, а потом повторяющиеся часто
    return 0;
}