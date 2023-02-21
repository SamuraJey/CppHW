#include <iostream>
using namespace std;

extern int global_var = 123;
const extern int const_global_var = 934;

extern int task3_1 = 778;
extern int task3_2 = 665;

int main1()
{
    cout << "const_global_var from header " << const_global_var << endl;
    return 0;
}

