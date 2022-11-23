#include <iostream>
#include <string>
#include <fstream>
#include <math.h>
#include <iomanip>

using namespace std;

int main(int argc, char const *argv[])
{
    string filename = "input680.txt";
    string ofilename = "output680.txt";
    ifstream input(filename);

    if (!input){
        std::cout << "Error opening file" << std::endl;
        input.close();
        return 0;
    }

    ofstream output(ofilename);
    int N;
    unsigned int answ;
    input >> N;
    answ = (pow(2, N - 1) * 3);
    output << answ;

    input.close();
    output.close();
    return 0;
}