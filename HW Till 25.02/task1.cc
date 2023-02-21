#include <bits/stdc++.h>
#include "task1_header.h"

using namespace std;

int main(int argc, char const *argv[])
{
    cout << global_var << endl;
    cout << const_global_var << endl;
    main1();
    cout << "const_global_var from task1.cc " << const_global_var << endl;
    task3_1--;
    task3_2++;

    cout << task3_1 <<" "<< task3_2 << endl;

    
    return 0;
}
