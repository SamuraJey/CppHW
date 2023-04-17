#include "Version_Stack.hh"
#include <assert.h>

int main() {
    // создаем стек версий
    VersionStack versionStack;

    // Тест Push и Top
    versionStack.Push(1);
    versionStack.Push(2);
    assert(versionStack.Top() == 2);
    cout << "Test Push and Top passed!" << endl;
    // Тест Pop и Top
    versionStack.Pop();
    assert(versionStack.Top() == 1);
    cout << "Test Pop and Top 2 passed!" << endl;

    // Тест Rollback
    versionStack.Push(3);
    versionStack.Push(4);
    versionStack.Push(5);
    versionStack.Rollback(2);
    assert(versionStack.Top() == 2);
    cout << "Test Rollback passed!" << endl;

    // Тест Forget
    versionStack.Push(6);
    versionStack.Push(7);
    versionStack.Forget();
    assert(versionStack.Top() == -1);
    cout << "Test Forget passed!" << endl;

    // Тест invalid Rollback
    versionStack.Push(8);
    versionStack.Push(9);
    versionStack.Push(10);
    versionStack.Push(11);
    versionStack.Push(12);
    versionStack.Push(13);
    versionStack.Rollback(111); // неправильный ролбек ничего не делает, поэтому следующий вызов Top() должен вернуть 13
    assert(versionStack.Top() == 13);
    cout << "Test invalid Rollback passed!" << endl;

    cout << "All tests passed!" << endl;

    return 0;
}
