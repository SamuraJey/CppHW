#include <cstdlib>
#include <fstream>
#include <iostream>
using namespace std;


int main()
{
    string filename = "input4.txt";
    string ofilename = "output4.txt";
    ifstream input(filename);
    if (!input){
        std::cout << "Error opening file" << std::endl;
        return 0;
    }
    ofstream output(ofilename);
    string str1, str2;
    int ploho = 0;
    string test1, test2,test3,test4,test5,test6;

    for (int i = 0; i < 4; i++)
    {
        input >> str1;
        str2 += str1;
        //cout << str2 << endl;
    }
    for (int i = 0; i < 12; i++)
    {
        test1 = str2[i];
        test2 = str2[i+1];
        test3 = str2[i+4];
        test4 = str2[i+5];
        if (test1.compare(test2) == 0 && test3.compare(test4) == 0 && test1.compare(test3) == 0 && test2.compare(test4) == 0 && test1.compare(test4) == 0 && test2.compare(test3) == 0){
            ploho++;
        }
    }
    if (ploho > 0)
    {
        output << "No";
        cout << "НЕЕЕЕЕЕЕТ" << endl;
    } else 
    {
        output << "Yes";
        cout << "ДААААААА" << endl;
    }
    
    input.close();
    output.close();

}