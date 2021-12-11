#include <iostream>
using namespace std;
#include <vector>

vector<int> plusOne(vector<int> &digits)
{
    int i = digits.size() - 1;

    if (digits[i] == 9)
    {
        digits[i] = 0;
        int j = i - 1;
        while (j >= 0)
        {
            if (digits[j] == 9)
            {
                digits[j] = 0;
                j--;
            }
            else
            {
                digits[j]++;
                break;
            }
        }
        if (j < 0)
            digits.insert(digits.begin(), 1);
    }
    else
    {
        digits[i]++;
    }
    return digits;
}

int main()
{
    vector<int> digits = {8, 9, 9, 9, 9, 9};

    int i = digits.size() - 1;

    if (digits[i] == 9)
    {
        digits[i] = 0;
        int j = i - 1;
        // cout << "j = " <<j<< endl;
        while (j >= 0)
        {
            if (digits[j] == 9)
            {
                digits[j] = 0;
                j--;
            }
            else
            {
                digits[j]++;
                break;
            }
        }
        if (j < 0)
            digits.insert(digits.begin(), 1);
    }
    else
    {
        digits[i]++;
    }

    for (int i = 0; i < digits.size(); i++)
        cout << digits[i] << " ";
    cout << endl;
    system("pause");
    return 0;
}
