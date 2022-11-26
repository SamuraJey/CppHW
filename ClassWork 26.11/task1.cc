/*
Loops1. Дано целое неотрицательное число N. 
Найти число, составленное теми же десятичными цифрами, 
что и N, но в обратном порядке. Запрещено использовать массивы.
*/

#include <iostream>

using namespace std;

int main()
{
    long long unsigned int num, answ = 0;
    cin >> num;

    while (num > 0)
    {
        answ = 10 * answ + (num % 10);
        num = num / 10;
    }

cout << answ << endl;
}
