#include<bits/stdc++.h>

using namespace std;

int main() {
    int N, M, counter = 0 , i;
    long long max_num, k;
    cin >> N >> M;
    if (N == M) 
    {
        cout << counter;
        return 0;
    }
    while (N % 2 == 0 && M % 2 == 0)
    {
        N /= 2;
        M /= 2; 
    }
    while (N % 3 == 0 && M % 3 == 0) 
    {
        N /= 3;
        M /= 3;
    }
    // считаем несовпадающие
    while (N % 2 == 0)
    {
        N /= 2;
        counter++;
    }
    while (N % 3 == 0)
    {
        N /= 3;
        counter++;
    }
    while (M % 2 == 0)
    {
        M /= 2;
        counter++;
    }
    while (M % 3 == 0)
    {
        M /= 3;
        counter++;
    }
    if (N == M) 
    {
        cout << counter;
        return 0;
    }
    
    max_num = int(sqrt(max(N,M))); // max_num – правая граница диапазона чисел
    k = 2;                     // k – счетчик количества  простых чисел
    vector <int> f = {2, 3};            // массив простых чисел
    i = 5;                // В i находится текущее  нечетное число
    while (i <= max_num)
    {
        // проверка делимости i на простые числа из массива
        bool flag = 1;
        for (int j = 0; j < k; j++)
        {
            if (f[j] * f[j]>i) // простое
            {
                break;
            }
            if (i%f[j] == 0) // не простое
            {
                flag = 0;
            }
        }
        // дозапись в хвост массива простых  чисел}
        if (flag)
        {
            f.push_back(i);
            while (N % i == 0 && M % i == 0)
            {
                N /= i;
                M /= i;
            }
            while (N % i == 0)
            {
                N /= i;
                counter++;
            }
            while (M % i == 0)
            {
                M /= i; 
                counter++;
            }
            if (N == M) 
            {
                cout << counter;
                return 0;
            }
            k++;
        }
        i += 2;
    }
    if (N > 1)
    {
        counter++;
    }
    if (M > 1)
    {
        counter++;
    }

    cout << counter;
    return 0;
}
