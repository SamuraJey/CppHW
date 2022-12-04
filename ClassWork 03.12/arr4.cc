#include <bits/stdc++.h>

using namespace std;

template <typename T> string tostr(const T& t) // stackoverflow code here
{
    ostringstream os;
    os.precision(19); 
    os << fixed;
    os << t;
    return os.str();
}

int main() {
    long double a, b;
    int counter = 1, sizeOfPeriod, flagPeriod = 0;
    string answ;

    cin >> a >> b;
    long double k = a / b;
    answ = tostr(k);

    for(int i = 1; i <= (answ.size() / 2) - 1; i++)
    {
        for(int j = i + 2; j < answ.size() - 1; j++)
        {
            if(answ[j] == answ[j - i])
            {
                counter += 1;
            }
            else
            {
                counter = 1;
            }
        }
        if(counter != 1)
        {
            sizeOfPeriod = i;
            flagPeriod = 1;
            break;
        } 
    }

    while(counter > 0)
    {
        answ.erase(answ.end() - counter);
        counter--;
    }

    if(flagPeriod == 1)
    {
        answ = answ +')';
        answ.insert(answ.end() - (sizeOfPeriod + 1),'(');
    }

    cout << answ;
    return 0;
}

/*
https://ulearn.me/course/basicprogramming/Zadachi_na_seminar_0df250b0-6288-4810-be5e-0512e39618e2
Arr4. Превратить рациональную дробь a/b (0 < a < b < 100000) в десятичную. 
Возможен период. "1/6" должна превратиться в "0.1(6)"
*/
