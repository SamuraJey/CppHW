#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    string inStr, outStr, s;
    int len = 0;
    cin >> inStr >> outStr;

    if (inStr.size() != outStr.size()) // если длины строк не равны, то ответ No
    {
        cout << "No";
        return 0;
    }

    s = outStr + "#" + inStr; // объединяем строки в одну
    vector<int> p(1 + s.size(), 0); // создаем вектор p, в котором будем хранить префикс-функцию
    
    for (int i = 1; i < s.size(); i++)
    {
        while (len > 0 && s[i] != s[len]) // ищем максимальную длину общего префикса и суффикса
        {
            len = p[len];
        }

        if (s[i] == s[len]) // если символы совпали, то увеличиваем длину общего префикса и суффикса
        {
            len++;
        }
        p[i + 1] = len; // запоминаем длину общего префикса и суффикса
    }

    for (int i = 0; i < inStr.size() - len; i++) // проверяем, является ли строка inStr подстрокой outStr
    {
        if (inStr[i] != outStr[outStr.size() - 1 - i]) // если символы не совпадают, то ответ No
        {
            cout << "No";
            return 0;
        }
    }
    cout << "Yes\n" << inStr.size() - len; // если все символы совпали, то ответ Yes и сдвиг строки = длине строки - длине общего префикса и суффикса
    return 0;
}
