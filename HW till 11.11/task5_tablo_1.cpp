 #include <iostream>
#include <vector>
#include <cstdlib>
#include <fstream>
#include <iostream>
using namespace std;

using namespace std;

int main() {
    int n, m, c;

    string filename = "input5.txt";
    string ofilename = "output5.txt";
    ifstream input(filename);

    if (!input){
        std::cout << "Error opening file" << std::endl;
        return 0;
    }
    ofstream output(ofilename);

    input >> n >> m;
    vector <string> l(n);
    bool y = 1;
    for (int z = 0; z < n; z++)
        input >> l[z];
    for (int z = 0; z < n; z++)
        for (int x = 0; x < m; x++) {
            input >> c;
            if (l[z][x] == '.') y = y;
            if (l[z][x] == 'B') y = y && (c == 1 || c == 3 || c == 5 || c == 7);
            if (l[z][x] == 'G') y = y && (c == 2 || c == 3 || c == 6 || c == 7);
            if (l[z][x] == 'R') y = y && (c == 4 || c == 5 || c == 6 || c == 7);
        }

    if (y)  output << "YES"; else output << "NO";
    input.close();
    output.close();
}