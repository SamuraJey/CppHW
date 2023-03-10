#include <iostream>
#include <string>
#include <fstream>
using namespace std;


int main() {
    string filename = "input7.txt";
    string ofilename = "output7.txt";
    ifstream input(filename);

    if (!input){
        std::cout << "Error opening file" << std::endl;
        return 0;
    }
    ofstream output(ofilename);

    string str;
    int n;
    int flag = 0;
    input >> n;
    string t_char = "ABCEHKMOPTXY"; //АВСЕНКМОРТХУ
    string t_digit = "0123456789";
    
    for(int i = 0; i < n; ++i){
        input >> str;
        if(str.size() != 6) {
          output << "No" << endl;
          continue;
        }
        for (int j = 0; j < str.size(); j++){
            flag = 0;
            int pos = t_char.find(str[j]);
            int npos = t_digit.find(str[j]);
            switch (j)
            {
            case 0:
                if(pos == -1){
                    flag = 1;
                    //cout << "No" << endl;
                    continue;
                }
                break;
            case 1:
                if(npos == -1){
                    flag = 1;
                    //cout << "No" << endl;
                    continue;
                }
                break;
            case 2:
                if(npos == -1){
                    flag = 1;
                    //cout << "No" << endl;
                    continue;
                }
                break;
            case 3:
                if(npos == -1){
                    flag = 1;
                    //cout << "No" << endl;
                    continue;
                }
                break;
            case 4:
                if(pos == -1){
                    flag = 1;
                    //cout << "No" << endl;
                    continue;
                }
                break;
            case 5:
                if(pos == -1){
                    flag = 1;
                    //cout << "No" << endl;
                    continue;
                }
                break;
            default:
                //seems that default is never triggered, idk why
                //flag = 0;
                cout << "DEFAULT TRIGGERED" << endl;
            }
            
            //cout << "Yes" << endl;
        }
        if (flag == 0) {
            output << "Yes" << "\n";
            //break;
        }
        else {
            output << "No" << "\n";
            //break;
            }
        }

    input.close();
    output.close();
    return 0;
}