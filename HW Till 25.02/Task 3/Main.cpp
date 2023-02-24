#include "iostream"
#include "Swap.h"

using namespace std;

int a = 228, b = 1337;

int main()
{
    auto [rt, jk] = Swap(a, b);
    cout << rt << " " << jk << endl;
}