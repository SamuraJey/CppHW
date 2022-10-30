#include <iostream>
using namespace std;

int main() {
    int counter = 0;

    for (int i = 0; i < 1000; i++) {
        if ((i % 3) == 0)
            counter += i;
        if ((i % 5) == 0)
            counter += i;
        if ((i % 15) == 0)
            counter -= i;
    }
    cout << counter << endl;
}
