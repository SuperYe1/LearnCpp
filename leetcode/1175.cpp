#include "oftenUse.hpp"
#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1e9 + 7;
int countPrimes(int n)
{
    int num = 0;
    vector<int> isprime(n, 1);
    vector<int> primes;
    for (int i = 2; i < n; i++)
    {
        if (isprime[i])
        {
            num++;
            primes.push_back(i);
        }
        for (int j = 0; j < primes.size() && i * primes[j] < n; ++j)
        {
            isprime[i * primes[j]] = 0;
            if (i % primes[j] == 0)
            {
                break;
            }
        }
    }
    return num;
}
int numPrimeArrangements(int n)
{
    int num = countPrimes(n+1);
    long long temp = 1;

    for (int i = 1; i <= n - num; i++)
    {
        temp *= i;
        temp %= MOD;
    }
    for (int i = 1; i <= num; i++)
    {
        temp *= i;
        temp %= MOD;
    }
    return temp;
}
int main()
{
    cout << countPrimes() << endl;
    cout << numPrimeArrangements(2) << endl;
    system("pause");
    return 0;
}