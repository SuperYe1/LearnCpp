#include "oftenUse.hpp"
#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

class MyCalendar
{
private:
    map<int, int> orderBook;

public:
    MyCalendar()
    {
        orderBook = map<int, int>();
        orderBook[-1] = 0;
    }

    bool book(int start, int end)
    {
        auto it = orderBook.upper_bound(start);
        auto pre = prev(it);
        if (pre->second > start || (it != orderBook.end() && it->first < end))
            return false;
        orderBook[start] = end;
        return true;
    }
};
int main()
{
    MyCalendar my = MyCalendar();
    cout << (my.book(37, 50) ? "true" : "false") << endl;
    cout << (my.book(35, 50) ? "true" : "false") << endl;

    system("pause");
    return 0;
}