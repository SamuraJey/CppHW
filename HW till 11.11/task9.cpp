#include <iostream>
#include <vector>
#include <fstream>
#include <iostream>

using namespace std;


int main() 
{
    string filename1, filename2, filename3;
    /*
    cin >> filename1 >> filename2 >> filename3;
    ifstream input1(filename1);
    ifstream input2(filename2);
    */
    ifstream input1("in1");
    ifstream input2("in2");
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
        //cout << var1 << "before" << endl;
        input1 >> var1;
        if ((j % 10) == 9)
        {
            cout << arr[((j+1) / 10)] << endl << endl;
            //j++;
        }
        if (var1 > 0)
        {
            j++;
            cout << var1 << endl;
        }
        else
        {
            continue;
        }
        //cout << endl;
        //cout << answ << endl;
    
    }
    
}