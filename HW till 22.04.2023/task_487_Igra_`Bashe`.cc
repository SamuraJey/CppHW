#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

/*
Этот код решает задачу 487 "Игра "Баше"" в системе проверки задач acmp.ru
только вот этот ******** сайт не принимает задачу на первом тесте, хотя вывод вроде правильный. >:(
Программа выводит:
    F
    F
    T

А сайт хочет:
    F
    F
    T

    В ЧЕМ МЕМ??????? шизосайт.
*/

int main() 
{
    int n, k, p;
    cin >> n >> k >> p;

    vector<int> moves(p);
    for (int i = 0; i < p; i++) 
    {
        cin >> moves[i];
    }

    vector<bool> correct(p, true); // все ходы считаем правильными

    int remaining = n;
    int player = p % 2; // определяем, кто сделал последний ход

    for (int i = p - 1; i >= 0; i--) 
    {
        int m = moves[i];
        remaining -= m;
        if (remaining <= 0) 
        {
            // кто-то взял последний билет, игра закончена
            break;
        }
        if (m > remaining || m > k) 
        {
            // ход невозможен, игра закончена
            break;
        }
        if (remaining <= k) 
        {
            // на столе осталось не более k билетов, можно взять все оставшиеся
            correct[i] = (remaining % (k + 1) != 1);
            break;
        }
        // проверяем все возможные варианты ходов и выбираем наилучший
        bool found = false;
        for (int j = 1; j <= k; j++) 
        {
            if (remaining - j <= 0) 
            {
                break;
            }
            if ((remaining - j) % (k + 1) == 0) 
            {
                found = true;
                break;
            }
        }
        if (!found) 
        {
            // текущий ход был ошибочным
            correct[i] = false;
        }

        player = 1 - player; // меняем игрока
    }

    // выводим результаты анализа ходов
    for (int i = 0; i < p; i++) 
    {
        cout << (correct[i] ? "F" : "T");
        if (i != p-1) 
        { // Если текущая строка не последняя, добавляем новую строку
            cout << endl;
        }
    }


    return 0;
}
