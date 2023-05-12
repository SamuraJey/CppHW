#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main()
{
    // открытие файлов для чтения и записи

    int N;
    cin >> N;

    // нахождение числа, состоящего из N цифр 1
    string ones(N, '1');
    long long number = stoll(ones);

    // перебор чисел, полученных заменой цифр на 2
    while (number % (1 << N) != 0)
    {
        // замена цифр на 2
        for (int i = N - 1; i >= 0; i--)
        {
            if (ones[i] == '1')
            {
                ones[i] = '2';
                break;
            }
            else if (ones[i] == '2')
            {
                ones[i] = '1';
            }
        }
        number = stoll(ones);
    }

    // вывод результата в выходной файл
    cout << ones << endl;

    return 0;
}