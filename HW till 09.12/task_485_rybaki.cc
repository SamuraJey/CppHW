#include<bits/stdc++.h>

using namespace std;

int main()
{
    int N, K;
    int answ = 1, prob = 1;
    cin >> N >> K;
    for (int i = 0; i < N+1; i++)
    {
        if (prob % N == K && prob - K > 0)
        {
            prob /= N;
            prob *= N - 1;
            continue;
        }
        else
        {
            answ++;
            prob = answ;
            i = 0;
        }
    }
    cout << answ;

    return 0;
}
