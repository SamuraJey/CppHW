#include <iostream>

using namespace std;
// clion test
int main()
{
    int num;

    cout << "Enter number: ";
    cin >> num;
    cout << "Lowest digit is: " << num / 10 << endl;
    cout << "Highest digit is: " << num % 10 << endl;
}