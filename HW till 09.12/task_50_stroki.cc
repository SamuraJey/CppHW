#include<bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    string first, second, temp;
    int counter = 0, answ = 0;
    cin >> first;
    cin >> second;

    for (size_t i = 0; i < second.size(); i++)
    {
        counter = 0;
        while (counter <= first.size() - second.size() && counter >= 0 )
        {
            counter = first.find(second, counter);
            if(counter != -1)
            {
                answ++;
            }
            if (counter >= 0)
            {
                counter++;
            }
        }
        temp = second.substr(1, second.size() - 1 + second[0]);
        if (temp == second)
        {
            break;
        }
        second = temp;
    }
    cout << answ;
    return 0;
}
