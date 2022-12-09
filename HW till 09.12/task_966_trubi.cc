#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
    int num, time, temp_time = 0, volume = 0, speed = 0;
    vector <vector <int>> arr(3,(vector <int>(1000)));

    cin >> num;
    for (size_t i = 0; i < num; i++)
    {
        cin >> arr[0][i] >> arr[1][i] >> arr[2][i];
    }

    cin >> time;

    while (temp_time < time)
    {
        for (size_t i = 0; i < num; i++)
        {
            if (arr[0][i] <= temp_time && arr[1][i] > temp_time)
            {
                speed += arr[2][i];
            }
        }
        volume += speed;
        speed = 0;
        if (volume < 0)
        {
            volume = 0;
        }
        temp_time++;
    }
    cout << volume;
    return 0;
}
