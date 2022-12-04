#include <iostream>

using namespace std;

int nod(int a, int b)
{
    while (a > 0 && b > 0)
        if (a > b)
        {
            a = a%b;
        }
        else
        {
            b = b%a;
        }

    return a + b;
}

int main () {
    int m;
    int n;
    cin >> m >> n;
    --n; --m;
    if (m == n)
    {
        printf("%d", n);
        return 0;
    }

    int gcd = nod(m, n);
    int res = n + m - gcd;
    printf("%d", res);

    return 0;
}

/*
https://acm.timus.ru/problem.aspx?num=1139
1139. Городские кварталы
Ограничение времени: 1.0 секунды
Ограничение памяти: 64 МБ
Кварталы города Фишбурга имеют квадратную форму. Их ограничивают N авеню, идущих с юга на север, и M улиц, идущих с востока на запад. Вертолёт взлетел на самом юго-западном перекрёстке и пролетел по прямой до самого северо-восточного перекрёстка. Над сколькими кварталами он пролетел?
Замечание. Квартал представляет собой внутреннюю область квадрата (граница квадрата не является частью квартала).
Исходные данные
Ввод содержит N и M, разделённые пробелами. 1 < N, M < 32 000.
Результат
Количество кварталов, над которыми пролетел вертолёт.
Примеры
исходные данные	результат
4 3
4
3 3
2
*/
