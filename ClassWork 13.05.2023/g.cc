#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main()
{
    int N;
    cin >> N;

    // нахождение числа, состоящего из N цифр 1
    string ones(N, '1');
    cout << ones << endl;
    unsigned long long number = stoull(ones);

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
        number = stoull(ones);
    }

    // вывод результата в выходной файл
    cout << ones << endl;

    return 0;
}