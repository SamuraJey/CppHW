#include <iostream>

using namespace std;

int main()
{
    int a, b, x, y, z;
    cin >> x;
    cin >> y;
    cin >> z;
    cin >> a;
    cin >> b;

    if ((((a - x) >= 0) && ((b - y) >= 0)) || (((a - y) >= 0) && (b - x) >= 0) || ((((a - x) >= 0) && (b - z) >= 0 ) || (((b - x) >= 0) && ((a - z) >= 0))) || (((a - y) >= 0) && (b - z) >= 0) || (((b - y) >= 0) && ((a - z) >= 0)))
    {
        cout << "Пройдет" << endl;
        return 0;
    }
    cout << "Не пройдёт" << endl;

    return 0;
}

/*
https://ulearn.me/course/basicprogramming/Zadachi_na_seminar_609e4aa9-0d76-4e33-90a8-b3340b266391
Пролезет ли брус со сторонами x, y, z в отверстие со сторонами a, b, если его разрешается поворачивать на 90 градусов?
*/