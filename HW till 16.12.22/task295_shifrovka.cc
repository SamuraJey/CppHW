#include <bits/stdc++.h>

using namespace std;

int main() 
{
    string str, temp = "", compare, alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    cin >> str >> compare;
    vector <string> arr;

    for (int i = 0; i < 27; i++) // пройдем по всему алфавиту
    {
        for (int j = 0; j < str.length(); j++)
        {
            temp = temp + alphabet[(alphabet.find(str[j]) + i) % 26];
        }
        if (temp.find(compare) != -1) 
        {
            arr.push_back(temp);
        }
        temp = "";
    }
    if (arr.size() == 0) 
    {
        cout << "IMPOSSIBLE";
    }
    else
    {
        cout << arr[arr.size() - 1]; // именно этот вариант
    }
    return 0;
}
