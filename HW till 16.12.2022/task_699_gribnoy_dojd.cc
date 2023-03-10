#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>
using namespace std;

int main() {
    int n, t;
    double minGrib, grib;
    cin >> n >> t;

    vector <double> arr1(n);
    vector <double> arr2(n);
    vector <double> arr3(n);

    for (int i = 0; i < n; i++) 
    {
        cin >> arr1[i] >> arr2[i] >>arr3[i];
    }
    if (n == 1) 
    {
    cout << fixed << setprecision(2) << t;
    return 0;
    }

    minGrib = 200;
    for (int i = 0;i < n - 1; i++)
    {
        for (int c = i + 1; c < n; c++) 
        {
            grib = sqrt((arr1[i] - arr1[c]) * (arr1[i] - arr1[c]) + (arr2[i] - arr2[c]) * (arr2[i] - arr2[c]));
            grib = grib - arr3[i] - arr3[c];
            if (grib <= 0)
            { // если грибы уже соприкасаются
                cout << "0.00"; return 0;
            }
            if (grib < minGrib)
            {
                minGrib = grib;
            } // находим минимальное расстояние
        }
    }
    if (minGrib / 2 > t)
    {
        cout << fixed << setprecision(2) << t; 
        return 0;
    }
    else
    {
        cout << fixed << setprecision(2) << minGrib/2;
    }
    return 0;
}