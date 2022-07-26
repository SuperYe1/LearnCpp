#include "oftenUse.hpp"
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<int> asteroidCollision(vector<int> &asteroids)
{
    vector<int> st;

    for (auto aster : asteroids)
    {
        bool alive = true;
        while (alive && !st.empty() && st.back() > 0 && aster < 0)
        {
            alive = st.back() < -aster;
            if (st.back() <= -aster)
                st.pop_back();
        }
        if (alive)
            st.push_back(aster);
    }

    return st;
}
/*
vector<int> asteroidCollision(vector<int> &asteroids)
{
    int index = 0;
    while (index < (int)asteroids.size() - 1)
    {
        if (asteroids[index] > 0 && asteroids[index] * asteroids[index + 1] < 0)
        {
            if (abs(asteroids[index]) == abs(asteroids[index + 1]))
            {
                asteroids.erase(asteroids.begin() + index, asteroids.begin() + index + 2);
                if(index>0)
                    index--;
            }
            else if (abs(asteroids[index]) < abs(asteroids[index + 1]))
            {
                asteroids.erase(asteroids.begin() + index);
                if(index>0)
                    index--;
            }
            else
            {
                asteroids.erase(asteroids.begin() + index +1);
            }
        }
        else
            index++;
    }
    return asteroids;
}*/

int main()
{
    vector<int> temp = {1, 1, -1, -2};
    vector<int> a = asteroidCollision(temp);
    for (auto i : a)
        cout << i << " ";
    cout << endl;
    system("pause");
    return 0;
}