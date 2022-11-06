#include <cstdlib>
#include <fstream>
#include <iostream>
using namespace std;


int main()
{
    string filename = "input4.txt";
    string ofilename = "output4.txt";
    ifstream input(filename);
    ofstream output(ofilename);
    string str1, str2;
    int ploho = 0;
    string test1, test2,test3,test4,test5,test6;

    for (int i = 0; i < 4; i++)
    {
        input >> str1;
        str2 += str1;
    }
    for (int i = 0; i < 9; i++)
    {
        test1 = str2[i];
        test2 = str2[i+1];
        test3 = str2[i+4];
        test4 = str2[i+5];
        //test5 = str2[i+5];
        //test6 = str2[i+6];
        //if (str2[i] == str2[i+1] == str2[i+4] == str2[i+5]) {
        
        if (test1.compare(test2) == 0 && test3.compare(test4) == 0 && test1.compare(test4) == 0){
            ploho++;
        }
    }
    if (ploho > 0)
    {
        output << "No";
    } else 
    {
        output << "Yes";
    }
    
    input.close();
    output.close();

}