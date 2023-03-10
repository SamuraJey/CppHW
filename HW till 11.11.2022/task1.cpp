using namespace std;
#include <cstdlib>
#include <time.h>
#include <iostream>

const int ABSLIMIT = 1000;

int Rrand(int range_min, int range_max)
{
    return rand() % (range_max - range_min + 1) + range_min;
}
int main()
{
    int ArrSize;
    int x = 0;
    cin >> ArrSize;
    int arr[ArrSize];

    srand(static_cast<unsigned int>(time(NULL)));

    for (unsigned int i = 0; i < ArrSize; i++)
    {
        arr[i] = Rrand(-ABSLIMIT, ABSLIMIT);
    }

    for (int j = 0; j < ArrSize; j++)
    {
        if (x < arr[j])
        {
            x = arr[j];
        }
    }
    /*
    for (int k = 0; k < ArrSize; k++)
    {
        cout << k << "   " << arr[k] << endl;
    }
    */
    cout << x << endl;
}
