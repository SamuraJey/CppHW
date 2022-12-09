#include<bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    int zarplata, comission, num_of_100, ostatok;
    cin >> zarplata;
    num_of_100 = zarplata / 107;
    ostatok = zarplata % 107;
    if (ostatok > 7)
    {
        cout << num_of_100 * 100 + ostatok - 7 << ' ' << num_of_100 * 7 + 7;
    }
    else
    {
        cout << num_of_100 * 100 << ' ' << num_of_100 * 7;
    }
    
    
    return 0;
}
