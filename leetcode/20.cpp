#include <iostream>
using namespace std;
#include <vector>

bool isValid(string s)
{
    if (s == "")
        return true;
    vector<char> isEmpty;
    isEmpty.push_back(s[0]);
    for (int i = 1; i < s.size(); i++)
    {
        if (isEmpty.empty())
        {
            isEmpty.push_back(s[i]);
        }
        else if (s[i] == isEmpty.back() + 1 || s[i] == isEmpty.back()+ 2)
            isEmpty.pop_back();
        else
            isEmpty.push_back(s[i]);
    }
    return isEmpty.empty();

    // for (int i = 1; i < s.size(); i++)
    // {
    //     if (s[i] == isEmpty.back() + 1 || s[i] == isEmpty.back() + 2)
    //         isEmpty.pop_back();
    //     else
    //         isEmpty.push_back(s[i]);
    // }
    // return isEmpty.empty();
}

int main()
{
    string s = "(){}()";
    cout << isValid(s) << endl;
    system("pause");
    return 0;
}
