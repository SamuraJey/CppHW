#include <iostream>

using namespace std;

int main()
{
    int hours1, hours2, minute1, minute2, seconds1, seconds2, answArray[10] = {0,}, tempArray[60] = {0,};

    char delimiter;

    cin >> hours1 >> delimiter >> minute1 >> delimiter >> seconds1;

    cin >> hours2 >> delimiter >> minute2 >> delimiter >> seconds2;

    while ((hours1 < hours2) || ((hours1 == hours2) && ((minute1 < minute2) || ((minute1 == minute2) && (seconds1 <= seconds2))))){
        tempArray[hours1]++;
        tempArray[minute1]++;
        tempArray[seconds1]++;
        seconds1++;
        if(seconds1==60)
        {
            seconds1 = 0;
            minute1++;
        }
        if(minute1==60)
        {
            minute1 = 0;
            hours1++;
        }
    }

    for(int i = 0; i < 60; i++)
    {
        answArray[i/10] += tempArray[i];
        answArray[i%10] += tempArray[i];
    }

    for(int i = 0; i < 10; i++)
    {
        cout << answArray[i] << endl;
    }

    return 0;
}