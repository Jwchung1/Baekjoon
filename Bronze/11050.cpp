#include <iostream>
using namespace std;

int fact(int a)
{
    int result = 1;
    for(int i=1; i<=a; i++)
    {
        result *= i;
    }
    return result;
}

int main()
{
    int N,K;
    cin >> N >> K;
    int N_fact = fact(N);
    int K_fact = fact(K);
    int NmK_fact = fact(N-K);
    cout << N_fact/(K_fact*NmK_fact);
}