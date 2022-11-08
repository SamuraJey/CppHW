#include <iostream>
#include <vector>
#include <fstream>
#include <iostream>

using namespace std;
     
int main() {

    string filename = "input8.txt";
    string ofilename = "output8.txt";
    ifstream input(filename);

    if (!input){
        std::cout << "Error opening file" << std::endl;
        return 0;
    }
    ofstream output(ofilename);

    string s;
    int t1 = 1, t2 = 1, t3 = 1; //fibbo start numbers
    vector<int> a;
    input >> s;
    a.push_back(0); //pushing 0 as last element of array a

    for(int i = 0; i < s.size() || t3 < s.size(); ++i){
        t3 = t2 + t1;
        t1 = t2;
        t2 = t3;
        a.push_back(t3 - 1);
    }
    for(int i = 0; i < a.size(); ++i)
        if(a[i] < s.size()) {
        output << s.substr(a[i],1); //outputing single char from string a in position i
    }
    input.close();
    output.close();
}

