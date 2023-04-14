#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() 
{
    int n;
    cin >> n;

    vector<int> seconds(n);

    for (int i = 0; i < n; i++) 
    {
        int hours, minutes, secs;
        scanf("%d:%d:%d", &hours, &minutes, &secs);
        int timeInSeconds = hours * 3600 + minutes * 60 + secs;
        seconds[i] = timeInSeconds;
    }

    int bestTime = seconds[0];
    int minTimeDifference = abs(seconds[0] - (2 * 3600 * n));

    for (int i = 0; i < n; i++) 
    {
        int timeDifference = abs((2 * 3600 * n) - 2 * seconds[i]);
        if (timeDifference < minTimeDifference) 
        {
            minTimeDifference = timeDifference;
            bestTime = seconds[i];
        }
    }

    int hours = bestTime / 3600;
    int minutes = (bestTime % 3600) / 60;
    int seconds1 = bestTime % 60;

    if (hours == 0) 
    {
        hours = 12;
    }

    if (hours > 12) 
    {
        hours -= 12;
    }

    if (hours < 10) 
    {
        printf("%1d:%02d:%02d\n", hours, minutes, seconds1);
    } 
    else 
    {
        printf("%02d:%02d:%02d\n", hours, minutes, seconds1);
    }

    return 0;
}