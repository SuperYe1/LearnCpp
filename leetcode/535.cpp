#include "oftenUse.hpp"
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
private:
    unordered_map<int, string> database;
    int id;

public:
    Solution() { id = 0; }
    // Encodes a URL to a shortened URL.
    string encode(string longUrl)
    {
        id++;
        database[id] = longUrl;
        return string("http://tinyurl.com/") + to_string(id);
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl)
    {
        int p = shortUrl.rfind('/')+1;
        int key = stoi(shortUrl.substr(p,shortUrl.size()-p));
        return database[key];
    }
};

int main()
{

    system("pause");
    return 0;
}