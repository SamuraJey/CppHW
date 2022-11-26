#include <math.h>
#include <iostream>

using namespace std; 

int main()
{
    double people_quantity, orig_raiting, target_raiting, answ, people_min, people_max, people;
    int sum_of_reviews;

    cin >> orig_raiting >> target_raiting >> people_quantity; 

    if (target_raiting > orig_raiting)
    {
        cout << "Impossible" << endl;
        return 0;
    }
     
    sum_of_reviews = ceil(orig_raiting * people_quantity);

    target_raiting = target_raiting + 0.049; 
    answ = (sum_of_reviews - target_raiting * people_quantity) / (target_raiting - 1);
    people_min = round((round(answ) + sum_of_reviews) / (people_quantity + round(answ)) * 100) / 100;
    people_max = round((round(answ) + 1 + sum_of_reviews) / (people_quantity + round(answ) + 1) * 100) / 100;

    if (people_min >= target_raiting-0.049 && people_min <= target_raiting)
    {
        cout << int(answ) << endl;
    }
    else
    {
    if (people_max >= target_raiting - 0.049 && people_max <= target_raiting)
    {
        cout << int(answ + 1) << endl;
    }
    else
    {
        cout << "Impossible" << endl;
    }
    }
}
