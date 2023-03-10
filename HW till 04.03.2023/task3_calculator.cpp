#include <iostream>

using namespace std;
/* Калькулятор не умеет в порядок действий и выполняет все действия слева направо */
int main()
{
    int res;
    cin >> res;
    while (True)
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
