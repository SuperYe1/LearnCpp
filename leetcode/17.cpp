#include <iostream>
using namespace std;
#include <unordered_map>
#include <vector>

void backtrack(vector<string> &combinations, const unordered_map<char, string> &phoneMap, const string &digits, int index, string &combination)
{
    if (index == digits.length())
    {
        combinations.push_back(combination);
    }
    else
    {
        char digit = digits[index];
        string letters = phoneMap.at(digit);
        for (char letter : letters)
        {
            combination.push_back(letter);
            backtrack(combinations, phoneMap, digits, index + 1, combination);
            combination.pop_back();
        }
    }
}

vector<string> letterCombinations(string digits)
{
    vector<string> combinations;
    if (digits.empty())
    {
        return combinations;
    }
    unordered_map<char, string> phoneMap{
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"}};
    string combination;
    backtrack(combinations, phoneMap, digits, 0, combination);
    return combinations;
}



int main()
{
    string digits = "23";
    vector<string> str1 = letterCombinations(digits);


    for (int i = 0; i < str1.size(); i++)
    {
        cout << str1[i] << endl;
        // cout << str[i].size() << endl;
    }

    system("pause");
    return 0;
}
