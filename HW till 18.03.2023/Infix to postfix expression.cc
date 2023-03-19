#include <iostream>
#include <stack>
#include <string>
#include <sstream>
#include <cctype>

using namespace std;

bool is_operator(char c)
{
    return c == '+' || c == '-' || c == '*' || c == '/';
}

int precedence(char op)
{
    if (op == '+' || op == '-')
    {
        return 1;
    } else if (op == '*' || op == '/')
    {
        return 2;
    } else {
        return 0;
    }
}

string infix_to_postfix(const string& infix)
{
    stack<char> op_stack;
    stringstream postfix;
    for (const char c : infix)
    {
        if (isdigit(c))
        {
            postfix << c;
        }
        else if (c == '(')
        {
            op_stack.push(c);
        }
        else if (c == ')')
        {
            while (!op_stack.empty() && op_stack.top() != '(')
            {
                postfix << op_stack.top();
                op_stack.pop();
            }
            if (!op_stack.empty() && op_stack.top() == '(')
            {
                op_stack.pop();
            }
        } else if (is_operator(c))
        {
            while (!op_stack.empty() && is_operator(op_stack.top()) &&
                   precedence(op_stack.top()) >= precedence(c))
            {
                postfix << op_stack.top();
                op_stack.pop();
            }
            op_stack.push(c);
        }
    }
    while (!op_stack.empty())
    {
        postfix << op_stack.top();
        op_stack.pop();
    }
    return postfix.str();
}

int evaluate_postfix(const string& postfix)
{
    stack<int> val_stack;
    for (const char c : postfix)
    {
        if (isdigit(c))
        {
            val_stack.push(c - '0');
        } 
        else if (is_operator(c))
        {
            int val2 = val_stack.top();
            val_stack.pop();
            int val1 = val_stack.top();
            val_stack.pop();
            switch (c)
            {
                case '+':
                    val_stack.push(val1 + val2);
                    break;
                case '-':
                    val_stack.push(val1 - val2);
                    break;
                case '*':
                    val_stack.push(val1 * val2);
                    break;
                case '/':
                    val_stack.push(val1 / val2);
                    break;
            }
        }
    }
    return val_stack.top();
}

int main()
{
    string infix;
    cout << "Enter an infix expression: ";
    getline(cin, infix);

    string postfix = infix_to_postfix(infix);
    int result = evaluate_postfix(postfix);

    cout << "Postfix expression: " << postfix << endl;
    cout << "Result: " << result << endl;

    return 0;
}