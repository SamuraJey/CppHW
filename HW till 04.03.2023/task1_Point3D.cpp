#include <iostream>

using namespace std;

struct Point3d
{
    int x, y, z;
    Point3d(int argx, int argy, int argz)
    {
        x = argx;
        y = argy;
        z = argz;
    }
    Point3d()
    {
        x = 0;
        y = 0;
        z = 0;
    }
    Point3d(int one_arg)
    {
        x = one_arg;
        y = one_arg;
        z = one_arg;
    }

    void Printer()
    {
        cout << x << " " << y << " " << z << endl;
    }
};


int main(int argc, char const* argv[])
{

    Point3d t(1, 5, 6);
    Point3d kul;
    Point3d lul(123);

    t.Printer();
    kul.Printer();
    lul.Printer();

    return 0;
}
