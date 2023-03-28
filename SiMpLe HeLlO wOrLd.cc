#include <iostream>
#include <string>

class HellOwWorlD
{
public:
    HellOwWorlD()
    {
        H[0] = 'H';
        e = 'e';
        l = 'l';
        lO = 'l';
        W = 'W';
        o = 'o';
        r = 'r';
        lD = 'l';
        d = 'd';
        u = ' ';
        exclam = '!';
    }

    std::string toString()
    {
        std::string s;
        s += H[0];
        s += e;
        s += l;
        s += lO;
        s += o;
        s += u;
        s += W;
        s += o;
        s += r;
        s += lD;
        s += d;
        s += exclam;
        return s;
    }

private:
    char H[1];
    char e;
    char l;
    char lO;
    char u;
    char W;
    char o;
    char r;
    char lD;
    char d;
    char exclam;
};

int main()
{
    HellOwWorlD h;
    std::cout << h.toString() << std::endl;
    return 0;
}
