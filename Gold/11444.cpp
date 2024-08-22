// 거대한 피보나치에 대한 분할정복 문제
// n이 짝수인 경우. f[n] = f[n/2]*(f[n/2+1] + f[n/2-1])
// n이 홀수인 경우. f[n] = f[(n+1)/2]^2 + f[(n-1)/2]^2
// 위 식을 기본 점화식으로부터 도출하고, 결과값을 저장해가면서 시간과 메모리 모두 절약해야한다.
// 솔루션 본 문제 **

#include <iostream>
#include <map>
#include <vector>
#define MOD 1000000007
using namespace std;
map<long long, long long> F;
long long fibo(long long k)
{
    if(F[k]) return F[k];
    int result;
    if(k%2 == 1){
        // 홀수면
        long long a = fibo((k+1)/2)%MOD;
        long long b = fibo((k-1)/2)%MOD;
        result = (a*a + b*b)%MOD;
    }
    else{
        // 짝수면
        long long a = fibo(k/2)%MOD;
        long long b = fibo(k/2 + 1)%MOD;
        long long c = fibo(k/2 -1)%MOD;
        result = (a*((b+c)%MOD))%MOD;
    }
    F[k] = result;
    return result;
}

int main()
{
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    long long n;
    cin >> n;
    F[0] = 0;
    F[1] = 1;
    F[2] = 1;
    cout << fibo(n);
}
