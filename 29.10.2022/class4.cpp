stan#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    double a,r,p;
    cin >> a >> r;
    a = a/2;
    p = 3.141592653589793;
    if (r <= a){
        cout << round(p*r*r*1000)/1000;
    }else{
        if (r >= ((a*sqrt(2)))){
            cout << round(a*a*4000)/1000;    
        }else{
        cout << round((4*(a*sqrt(r*r - a*a)) + (p*r*r)*(360 - 8 * acos(a/r)*180/p)/360)*1000)/1000;
        }
    }

    
}