#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, const char** argv) {

    string filename = "etofiel.txt";
    //string ofilename = "output385.txt";
    ifstream input(filename);

    if (!input)
    {
        cout << "Error opening file" << endl;
        return 0;
    }
    //ofstream output(ofilename);
    int n;
    input >> n;
    cout << n << endl;

}