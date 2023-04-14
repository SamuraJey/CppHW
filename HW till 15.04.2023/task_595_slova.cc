#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    string inStr, outStr, s;
    int len = 0;
    cin >> inStr >> outStr;

    if (inStr.size() != outStr.size())
    {
        cout << "No";
        return 0;
    }

    s = outStr + "#" + inStr;
    vector<int> p(1 + s.size(), 0);
    
    for (int i = 1; i < s.size(); i++)
    {
        while (len > 0 && s[i] != s[len])
        {
            len = p[len];
        }

        if (s[i] == s[len])
        {
            len++;
        }
        p[i + 1] = len;
    }

    for (int i = 0; i < inStr.size() - len; i++)
    {
        if (inStr[i] != outStr[outStr.size() - 1 - i])
        {
            cout << "No";
            return 0;
        }
    }
    cout << "Yes\n" << inStr.size() - len;
    return 0;
}
