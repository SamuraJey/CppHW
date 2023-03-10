#include <bits/stdc++.h>

using namespace std;

string intToString(int num, int base) // получаемем строкове представление от 0 до base
{
    string answ = "";
    while (num > 0)
    {
        answ = char(num % base) + answ;
        num = num / base;
    }
    return answ;
}

bool isPalindrom(string s) // проверка на то является ли
{
    bool k = 1;
    for (int i = 0; i < s.length() / 2; i++)
    {
        k = k && s[i] == s[s.length() - 1 - i];
    }
    return k;
}

int main() {
    string s;
    int number;
    cin >> number;
    vector <int> arr;

    for (int i = 2; i <= 36; i++) 
    {
        s = intToString(number, i);     // переделываем в строку символов
        if (isPalindrom(s))
        {
            arr.push_back(i); // запоминаем основание палиндрома
        }     
    }
    if (arr.size() == 0) 
    {
        cout << "none"; return 0; 
    }
    if (arr.size() == 1)
    {
        cout << "unique" << endl << arr[0]; return 0;
    }

    cout << "multiple" << endl;

    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}
