/*
task: Loops3. Если все числа натурального ряда записать подряд каждую цифру в своей позиции, то необходимо ответить на вопрос: какая цифра стоит в заданной позиции N.
т.е у нас есть ряд натуральных чисел где каждая цифра записана в отдельном индексе то есть ряд до 13 будет выглядеть так
[1] [2] [3] [4] [5] [6] [7] [8] [9] [1] [0] [1] [1] [1] [2] [1] [3]
Для упрощения жизни "нумеруем" его не с 0, а с единицы
*/

#include <iostream>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
    int counter = 0, len = 0, position;
    string num = "";
    cin >> position;
    int nn = position;

    if (position < 10)
    {
        cout << position << endl;
        return 0;
    }

    while (len < position)
    {
        counter++;
        num = to_string(counter);
        nn -= num.length();
        len += num.length();
    }

    cout << num[num.length() + nn - 1] << endl;
    return 0;
}
