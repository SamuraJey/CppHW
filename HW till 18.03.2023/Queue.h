#include <stack>

using namespace std;

class Queue {
public:
    // Добавить элемент в очередь
    void push(int x)
    {
        stack1.push(x);
    }

    // Удалить первый элемент из очереди
    void pop()
    {
        if (stack2.empty())
        {
            while (!stack1.empty())
            {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }
        stack2.pop();
    }

    // Получить первый элемент в очереди
    int front() 
    {
        if (stack2.empty())
        {
            while (!stack1.empty())
            {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }
        return stack2.top();
    }

    // Проверить, пуста ли очередь
    bool empty()
    {
        return stack1.empty() && stack2.empty();
    }

private:
    stack<int> stack1, stack2;
};
