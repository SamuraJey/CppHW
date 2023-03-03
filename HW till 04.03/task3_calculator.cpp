#include <iostream>

using namespace std;

int main()
{
    int res;
    cin >> res;
    while (1)
    {
        int tmp;
        char op;
        cin >> op;
        if (op == '=')
            break;
        cin >> tmp;
        switch (op) {
        case '/':
            if (tmp == 0)
            {
                cout << "division by zero!" << endl;
                exit(1);
            }
            res /= tmp;
            break;
        case '*':
            res *= tmp;
            break;
        case '+':
            res += tmp;
            break;
        case '-':
            res -= tmp;
            break; 
        default:
            exit(1);
        }
    }
    cout << res << endl;
}