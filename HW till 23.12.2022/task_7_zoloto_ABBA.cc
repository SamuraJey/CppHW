#include <bits/stdc++.h>

using namespace std;

int main()
{
    char str1[102] = "", str2[102] = "", str3[102] = "";
    cin >> str1 >> str2 >> str3;
    int num1 = strcmp(str1, str2);
    int num2 = strcmp(str1, str3);
    int num3 = strcmp(str2, str3);

    if ((strlen(str1) > strlen(str2)) || ((strlen(str1) == strlen(str2)) && num1 > 0))
    {
        if ((strlen(str1) > strlen(str3)) || ((strlen(str1) == strlen(str3)) && num2 > 0))
        {
            cout << str1;
        }
        else 
        {
            cout << str3;
        }
    }
    else 
    {
        if ((strlen(str2) > strlen(str3)) || ((strlen(str2) == strlen(str3)) && num3 > 0))
        {
            cout << str2;
        }
        else 
        {
            cout << str3;
        }
    }
       return 0;
}