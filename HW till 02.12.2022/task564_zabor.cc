#include <iostream>
#include <iomanip>
#include <math.h>
#include <vector>

using namespace std;

int main() 
{
    int n;
    double answ = 0;
    int number1, number2, number3;
    cin >> n;
    vector <int> a(100);
    //int a[1000] = { 0 };
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    if (n < 3) // из 1 или 2 кусков забора никак невозможно построить геометрическую фигуру
    { 
        cout << -1; 
        return 0;
    }

    for (int i = 0; i < n - 2; i++)
    {
        for (int j = i + 1; j < n - 1; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                if (a[i] + a[j] < a[k])
                {
                    break; // фигура не замкнется
                }
                double p = (a[i] + a[k] + a[j]) / 2.0;
                double s = p * (p - a[j])*(p - a[k])*(p - a[i]);
                if (s > answ) 
                {
                    answ = s;
                    number1 = i+1;
                    number2 = j+1;
                    number3 = k+1;
                }
            }
        }
    }

    if (answ == 0) // кажется, не нашлось подходящих фрагментов
    {
        cout << -1;
        return 0;
    }

    cout << fixed << setprecision(7) << sqrt(answ) << endl;
    //cout << setprecision(0) << number1 + 1 << " " << number2 + 1 << " " << number3 + 1;
    cout << setprecision(0) << number1 << " " << number2 << " " << number3;

    return 0;
}