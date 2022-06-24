#include <iostream>
#include <vector>
using namespace std;

string defangIPaddr(string address)
{
    string temp = "[.]";
    for (auto it = address.begin(); it < address.end(); ++it)
    {
        if (*it == '.')
        {
            it = address.erase(it);
            address.insert(it,temp.begin(),temp.end());
            it += 3;
        }
    }
    return address;
}

int main()
{
    string address = "255.100.50.0";
    cout << address << endl
         << defangIPaddr(address) << endl;
    system("pause");
    return 0;
}