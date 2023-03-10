#include <iostream>
#include <vector>
#include <fstream>
#include <iostream>

using namespace std;

int main() {

    string filename = "input9.txt";
    string ofilename = "output9.txt";
    ifstream input(filename);

    if (!input){
        std::cout << "Error opening file" << std::endl;
        input.close();
        return 0;
    }
    ofstream output(ofilename);

    string tmp, answ;
    int counter, pos;
    input >> tmp;
    pos = tmp.find('1');
    
    while (pos + 1)
    {
        counter = 0;
        for (int i = pos - 1; i >= 0; i--)
        {
            if (tmp[i] == '0')
            {
                counter++;
            }
            else
            {
                break;
            }
        }
        answ.push_back(97 + counter);
        pos = tmp.find('1', pos + 1);
    }
    
    output << answ;
    input.close();
    output.close();
}