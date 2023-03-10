#include <iostream>
using namespace std;

struct Point3d
{
private:
int x=1;
public:
void Print()
{
    cout << x << endl;
}
};

int main()
{
    Point3d a;

    
    a.Print();

}