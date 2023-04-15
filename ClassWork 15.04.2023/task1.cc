#include <iostream>
#include <stack>

using namespace std;

class MaxStack {
public:
    void Push(int value) 
    {
        // добавляем элемент в основной стек
        stack_.push(value);
        // проверяем, является ли он максимальным
        if (max_stack_.empty() || value >= max_stack_.top()) 
        {
            max_stack_.push(value);
        }
    }

    void Pop() 
    {
        if (stack_.empty()) 
        {
            return;
        }

        // удаляем элемент из основного стека
        int value = stack_.top();
        stack_.pop();

        // проверяем, являлся ли он максимальным
        if (value == max_stack_.top()) 
        {
            max_stack_.pop();
        }
    }

    int Top() 
    {
        return stack_.top();
    }

    bool Empty() 
    {
        return stack_.empty();
    }

    int GetMax() 
    {
        return max_stack_.top();
    }

private:
    stack<int> stack_;
    stack<int> max_stack_;
};

int main() 
{
    MaxStack maximumStack;

    maximumStack.Push(2);
    maximumStack.Push(5);
    maximumStack.Push(1);
    maximumStack.Push(3);

    /*
    Структура стека
    3
    1
    5
    2
    */

    cout << maximumStack.GetMax() << endl; // 5
    
    maximumStack.Pop();
    maximumStack.Pop();

    cout << maximumStack.GetMax() << endl; // 5
    maximumStack.Pop();

    /*
    Структура стека
    2
    */

    cout << maximumStack.GetMax() << endl; // 2
    maximumStack.Push(6);

    cout << maximumStack.GetMax() << endl; // 6

    return 0;
}
