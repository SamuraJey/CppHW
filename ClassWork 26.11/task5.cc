/*
Loops5. Дана строка из символов '(' и ')'. 
Определить, является ли она корректным скобочным выражением. 
Определить максимальную глубину вложенности скобок.
*/

#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
    int len, a = 0, count = 0;
    vector <int> list;
    string str;
    cin >> str;
    len = str.size();
    if (len == 0)
    {
        cout << "Error, no parenthesis";
        return 1;
    }
    for (int i = 0; i < len; i++)
    {
        if (str[i] == '(')
        {
            a++;
        }
        else
        {
            if (str[i] == ')')
            {
                if (i != len - 1 && str[i+1] != '(')
                {
                    count++;
                }
            a--;
            }
        }
        if (a == 0)
        {
            list.push_back(count);
            count = 0;
        }
    }
    sort(list.begin(), list.end());
    if (a == 0)
    {
        cout << list[list.size() - 1] + 1 << endl;
    }
    else
    {
        cout << "Incorrect sequence of parentheses" << endl;
    }

    return 0;
}
