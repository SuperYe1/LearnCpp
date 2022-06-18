#include <iostream>
using namespace std;

class Player1
{
    public:
    virtual int fun(int c) {}
private:
    int a;
    char b;
    double c;
};

int main()
{
    Player1 a;
    cout<<sizeof(Player1)<<endl;

    system("pause");
    return 0;
}
