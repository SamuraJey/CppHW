#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int v, t;
    float g = 9.81;
    float pi = 3.1415926535;
    float angle;

    cout << "enter speed: ";
    cin >> v;
    cout << "enter time: ";
    cin >> t;
    angle = asin(((g * t) / (2 * v))) * 180 / pi;
    cout << angle << endl;
}