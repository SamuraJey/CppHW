#include <bits/stdc++.h>

using namespace std;

string NumToString(int n)
{
    string tmp = "";
    while (n > 0)
    {
        tmp = char(n % 2 + '0') + tmp;
        n /= 2;
    }
    return tmp;
}

int StringToNum(string s) 
{
    int n = 0;
    for (int i = 0; i < s.size(); i++)
        n = n * 2 + int(s[i] - '0');
    return n;
}

int main() {
    int n;
    string answ, tempStr;
    
    cin >> n;
    answ = NumToString(n);
    tempStr = answ;

    for (int i = 0; i < answ.size(); i++)
    {
        tempStr = tempStr[tempStr.size() - 1] + tempStr.substr(0, tempStr.size() - 1);
        if (answ < tempStr)
        {
            answ = tempStr;
        }
    }
    cout << StringToNum(answ);
    return 0;
}
