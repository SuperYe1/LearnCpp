#include "oftenUse.hpp"
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int mctFromLeafValues(vector<int> &arr)
{
    int n = arr.size();
    if(n == 1)
        return arr[0];
    stack<int> st;
    st.push(INT_MAX);
    int res = 0;
    for(int i = 0; i < n; i++)
    {
        while(arr[i]>=st.top())
        {
            int temp = st.top();
            st.pop();
            res += temp * min(st.top(), arr[i]);
        }
        st.push(arr[i]);
    }
    while(st.size()>2)
    {
        int temp = st.top();
        st.pop();
        res += temp*st.top();
    }
    return res;
}
int main()
{

    system("pause");
    return 0;
}