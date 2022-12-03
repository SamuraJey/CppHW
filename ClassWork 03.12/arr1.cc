#include<bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector <int> arr = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    rotate(arr.begin(), arr.begin()+n, arr.end());

    /*
    изначальное решение было такое, но оказывается цикл вообще не нужен.

    for (size_t i = 0; i < n; i++)
    {
        rotate(arr.begin(), arr.begin()+1, arr.end());
    }
    */

    cout << endl;
    for (auto p : arr)
    {
        cout << p << " ";
    }

    return 0;
}

/*
https://ulearn.me/course/basicprogramming/Zadachi_na_seminar_0df250b0-6288-4810-be5e-0512e39618e2
Arr1. Дан массив чисел. Нужно его сдвинуть циклически 
на K позиций влево, не используя других массивов.
*/