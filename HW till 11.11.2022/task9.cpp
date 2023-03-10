#include <iostream>
#include <vector>
#include <fstream>
#include <iostream>

using namespace std;

int main() 
{
    string filename1, filename2, filename3;
    
    cin >> filename1 >> filename2 >> filename3;
    ifstream input1(filename1);
    ifstream input2(filename2);
    ofstream output(filename3);

    if (!input1 || !input2){
        std::cout << "Error opening files" << std::endl;
        return 0;
    }

    int var1, var2, answ;
    string arr[11] = {" ", "десятая", "двадцатая", "тридцатая", "сороковая", "пятидесятая", "шестидесятая", "семидесятая", "восмидесятая", "девяностая", "сотая"};
    int j = 0;
    int arrind = 0;

    while (!input1.eof())
    {
        
        input1 >> var1;
        if ((j % 10) == 0 && (j != 0))
        {
            output << arr[((j+1) / 10)] << endl << endl;
            
        }
        if (var1 > 0)
        {
            j++;
            output << var1 << endl;
            continue;
        }
        else
        {
            continue;
        }

    }

    while (!input2.eof())
    {
        input2 >> var2;
        if ((j % 10) == 0 && (j != 0))
        {
            output << arr[((j+1) / 10)] << endl << endl;
        }
        if (var2 > 0)
        {
            j++;
            output << var2 << endl;
            continue;
        }
        else
        {
            continue;
        }
    
    }

    input1.close();
    input2.close();
    output.close();
    return 0;
}