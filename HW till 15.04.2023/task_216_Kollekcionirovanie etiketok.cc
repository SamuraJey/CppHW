#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() 
{
    int n;
    cin >> n;

    vector<int> albums(n);
    int capacity = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> albums[i];
        capacity += albums[i]; // считаем общую вместимость
    }

    sort(albums.rbegin(), albums.rend()); // сортируем по убыванию

    int labels = 0;
    int currentCapacity = 0;

    for (int i = 0; i < n; i++) 
    {
        if (currentCapacity >= capacity / 2) // если вместимость уже больше половины, то выходим
        {
            break;
        }

        if (currentCapacity + albums[i] <= capacity / 2) // если вместимость меньше половины, то добавляем альбом
        {
            currentCapacity += albums[i];
            labels += albums[i];
        } 
        else // если вместимость больше половины, то добавляем разницу
        {
            labels += (capacity / 2 - currentCapacity); // добавляем разницу
            break;
        }
    }

    cout << labels << endl;
    return 0;
}
