#include <vector>
#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;

struct Rocket 
{
    int number;             // номер ракеты
    long long startTime;    // время старта
    long long speed;        // скорость ракеты
};

bool compareRockets(const Rocket& a, const Rocket& b) 
{
    return a.startTime < b.startTime;
}

int main() 
{
    long long time, velocity;
    vector<Rocket> rockets(4);
    long long multiplier = 1;  // специальный множитель, чтобы не мудохаться с точностью
    for (int i = 0; i < 4; i++)
     {
        cin >> time >> velocity;
        rockets[i].number = i;
        rockets[i].startTime = time;
        rockets[i].speed = velocity;
        multiplier *= velocity;
    }
    long long turnTime, distanceToStart; // время поворота и расстояние до точки старта
    cin >> turnTime >> distanceToStart;
    for (int i = 0; i < 4; i++) // считаем время "прибытия" ракет
    { 
        rockets[i].startTime = rockets[i].startTime * multiplier + distanceToStart * multiplier / rockets[i].speed;
    }
    turnTime *= multiplier;  // все величины времени подросли в mn раз, время поворота - тоже
    sort(rockets.begin(), rockets.end(), compareRockets);  // ракеты будут подлетать именно в этом порядке
    for (int i = 1; i < 3; i++) // дополнительная сортировка для определения доступности
    {    
        if (rockets[i].startTime == rockets[i + 1].startTime) // направления с одинаковым временем подлета
        {  
            if (abs(rockets[i - 1].number - rockets[i].number) == 2)
            {
                swap(rockets[i], rockets[i + 1]);
            }
        }
    }
    int count = 1;   // первая ракета точно будет отражена
    int i = 1;
    while (i < 4) // рассматриваем остальные направления
    {
        if (rockets[i - 1].startTime + turnTime * (abs(rockets[i].number - rockets[i - 1].number) % 2 == 0 ? 2 : 1) <= rockets[i].startTime) 
        {
            count++;
            i++;
        }
        else 
        {
            break;
        }
    }
    if (count < 4) 
    {
        cout << count;
    }
    else
    {
        cout << "ALIVE";
    }

    return 0;
}
