#include <iostream>
#include <math.h>
using namespace std;

int main() {
    int hour,answ, res1,res2, min;
    cin >> hour;
    cin >> min;
    hour = hour % 12;
    //min = min % 60;
    res1 = hour * 30;
    res2 = min * 6;
    answ = abs(res1 - res2);
    cout << res << endl;
}