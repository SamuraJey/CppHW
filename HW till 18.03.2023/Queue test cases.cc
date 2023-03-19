#include <iostream>
#include "Queue.h"

using namespace std;

int main() 
{
    Queue queue_example;

    // Добавление элементов в очередь
    queue_example.push(1);
    queue_example.push(2);
    queue_example.push(3);

    // Проверка, что первый элемент в очереди равен 1
    if (queue_example.front() != 1)
    {
        cout << "Ошибка: front() должен вернуть 1" << endl;
        return 1;
    }

    // Удаление первого элемента из очереди
    queue_example.pop();

    // Проверка, что первый элемент в очереди теперь равен 2
    if (queue_example.front() != 2)
    {
        cout << "Ошибка: front() должен вернуть 2" << endl;
        return 1;
    }

    // Добавление еще одного элемента в очередь
    queue_example.push(4);

    // Проверка, что первый элемент в очереди теперь равен 2
    if (queue_example.front() != 2) {
        cout << "Ошибка: front() должен вернуть 2" << endl;
        return 1;
    }

    // Удаление оставшихся элементов из очереди
    queue_example.pop();
    queue_example.pop();
    queue_example.pop();

    // Проверка, что очередь пуста
    if (!queue_example.empty()) {
        cout << "Ошибка: очередь должна быть пуста" << endl;
        return 1;
    }

    cout << "Все тесты прошли успешно" << endl;
    return 0;
}
