#include <iostream>
using namespace std;
#include <algorithm>
#include <vector>

string convert(string s, int numRows)
{
    if(numRows<2)
    {
        return s;
    }

    int strlength = s.size();
    vector<string> str(min(numRows, strlength));
    int row = 0;
    bool rowCon = false;

    for (int i = 0; i < strlength; i++)
    {
        str[row] = str[row] + s[i];
        if(row ==0||row==numRows-1)
        {
            rowCon = !rowCon;
        }
        row += rowCon ? 1 : -1;
    }

    string reStr;
    for(string c:str)
    {
        reStr += c;
    }

    return reStr;

}

int main()
{
    string s = "abcdefg";
    int nums = 3;
    string str = convert(s, nums);
    cout << str << endl;
    // int x = convert(s, nums);
    // cout << "x" << x << endl;

    system("pause");
    return 0;
}
