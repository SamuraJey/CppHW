#include <iostream>
#include <math.h>
using namespace std;

int main() {
    int h, t, v, x,min,max;
    max = 0;
    min = 10000;
    cin >> h >> t >> v >> x;
    for(int i = 0; i <= t; i++){
        if (((i*v) + ((t-i)*x)) >= h){
            if(i > max){
                max = i;
            }
            if(i < min){
                min = i;
            }
        }
    }
    cout << min << ' '<< max << endl;
}