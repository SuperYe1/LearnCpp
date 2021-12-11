#include <iostream>
#include <vector>
using namespace std;

vector<int> sortArrayByParityII(vector<int> &A)
{
    int n = A.size();
    int j = 1;
    for (int i = 0; i < n; i += 2)
    {
        if (A[i] % 2 == 1)
        {
            while (A[j] % 2 == 1)
                j += 2;
            swap(A[i], A[j]);
        }
    }
    return A;
}

int main()
{
    cout << 0 % 2 << endl;

    system("pause");
    return 0;
}
