#include <iostream>
#include <vector>
using namespace std;

int main() {
    int num, right, i, counter;
    cin >> num;
    right = num; // right – правая граница диапазона чисел
    counter = 2; // counter – счетчик количества  простых чисел
    vector <int> arr;
    arr.push_back(2);
    arr.push_back(3);
    i = 5;                // В i находится текущее нечетное число
    while (i <= right) {
        // проверим делимость i на простые числа в массиве
        bool flag = 1;
        for (int j = 0; j < counter; j++) 
        {
            if (arr[j] * arr[j] > i)// является простым
            {
                break; 
            }
            if (i % arr[j] == 0) // не является простым
            {
                flag = 0;
            }    
        }
        if (flag) 
        {
            arr.push_back(i);
            counter++;
        }
        i++;
        i++;
    }
    for (int z=0; z<arr.size();z++)
    {
        for (int x=z; x<arr.size();x++)
        {
            if (arr[z] + arr[x] == num) 
            {
                cout << arr[z] << " " << arr[x];
                return 0;
            }
        }
    }
    return 0;
}
