#include <cstdlib>
#include <fstream>
#include <iostream>
using namespace std;


int main()
{
    string filename = "input3.txt";
    string ofilename = "output3.txt";
    ifstream input(filename);
    ofstream output(ofilename);

    int w, h;
    int answ = 0;
    string str1, str2, str3;
    
    input >> h >> w;
    
    for (int i = 0; i < h; i++)
    {
        input >> str1;
        str2 += str1;
    }
    //cout << str2 << endl;
    str1 = "";

    for (int i = 0; i < h; i++)
    {
        input >> str1;
        str3 += str1;
    }

    for (int i = 0; i < str2.size(); i++)
    {
        if (str2[i] == 'B') {
            str2[i] = 'W';
        }
        else {
            str2[i] = 'B';
        }
    }
    
    for (int i = 0; i < str2.size(); i++)
    {
        if (str2[i] != str3[i]) {
            answ++;
        }
    }

    output << answ;
    input.close();
    output.close();
}
