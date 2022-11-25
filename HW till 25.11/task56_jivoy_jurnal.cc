#include <iostream>
#include <fstream>
#include <string>
#include <set>

using namespace std;

ifstream OpenFile(string input_file)
{
    string filename = input_file;
    ifstream input(filename);

    if (!input){
        std::cout << "Error opening file" << std::endl;
        input.close();
        return input;
    }
    return input;
}
ofstream OutputFile(string output_file)
{
    string ofilename = output_file;
    ofstream output(ofilename);
    return output;
}

int main()
{
    ifstream input = OpenFile("input56.txt");
    ofstream output = OutputFile("output56.txt");
    int n, m;
    int counter = 1;
    string a;
    set <string> friends; // множество друзей

    input >> n;

    for (int i = 0; i < n; i++)
    {
        input >> a;
        friends.insert(a);
    }

    input >> m;
    set <string> ff;

    for (int i = 0; i < m; i++)
    {
        input >> a;
        ff.insert(a);
    }

    
    output << "Friends: ";

    for (auto i : friends)
    {
        output << i;  // выводим список друзей
        if (counter < friends.size()) output << ", " ; // после последнего друга запятая не нужна, каунтер испольузется для того что бы предотвратить вывод запятой
        counter++;
    }

    counter = 1;
    output << endl << "Mutual Friends: ";

    for (auto z : friends) 
    {
        if (ff.find(z) != ff.end() && counter > 1) output << ", "; // если друг считает нас другом и не является первый, то выведем запятую
        if (ff.find(z) != ff.end()) { output << z; counter++; } // и друга
    }

    counter = 1;
    output << endl << "Also Friend of: ";

    for (auto z : ff) // по тому же принципу выводим тех, кто дружит с нами безответно
    {
        if (friends.find(z) == friends.end() && counter > 1) output << ", ";
        if (friends.find(z) == friends.end()) { output << z; counter++; }
    }
    input.close();
    output.close();
    return 0;
}