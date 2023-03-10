#include<bits/stdc++.h>

using namespace std;

int Convert(int base_in, int base_out, int num) //Функция перевода из системы счисления base_in в base_out числа num
{
    int t = 0, out_dec = 0, q = 0, out_t = 0;
    // Выполняем перевод из любой системы исчисления base_in в систему исчисления с основой 10
    // путем деления как это уже обговаривалось в предыдущем посте.
    for (int n_val = num; n_val >= 1; n_val /= 10)
    {
        out_dec += (n_val % 10) * int(pow(base_in, t++));
    }

    // Переводим из системы счисления с основой 10 в любую систему исчисления с основой base_out
    for (int n_val_t = out_dec; n_val_t >= 1; n_val_t /= base_out)
    {
        out_t += (n_val_t % base_out) * int(pow(10.0, q++));
    }
    return out_t;
}

 
int main()
{
    int A, B, number = 0;
    cin >> A;
    cin >> B;
    vector <int> arr = {1, 1, 1, 0, 0, 1, 0, 1};

    for(auto i : arr) // таким образом мы значения из массива записываем в виде нормального числа
    {
        number *= 10;
        number += i;
    }

    cout << Convert(A, B, number) << endl;
    return 0;
}

/*
https://ulearn.me/course/basicprogramming/Zadachi_na_seminar_0df250b0-6288-4810-be5e-0512e39618e2
Arr3. Перевести число из системы счисления с основанием A в систему с основанием B. 
Можно считать, что 2 ≤ A, B ≤ 10, а число дано в виде массива цифр.
*/