#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

int main(int argc, char const *argv[])
{
    string alphabet1 = "0123456789ABCDEFGHIJKLMNOPQ";
    string alphabet2 = "abcdefghijklmnopqrstuvwxyz ";
    string answ;
    int n = 2;

    string filename = "input73.txt";
    string ofilename = "output73.txt";
    ifstream input(filename);

    if (!input){
        std::cout << "Error opening file" << std::endl;
        input.close();
        return 0;
    }
    ofstream output(ofilename);
    input >> answ;

    for (int i = 0; i < answ.length(); i++)
    {
        int k = alphabet1.find(answ[i]) - n;
        while (k < 0) {
            k += 27;
        }
        n++;
        output << alphabet2[k];
    }
    input.close();
    output.close();
    return 0;
}
