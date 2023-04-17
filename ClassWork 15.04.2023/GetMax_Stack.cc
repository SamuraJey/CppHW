#include "GetMax_Stack.hh"

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
