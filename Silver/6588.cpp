#include <iostream>
#include <cstring>
using namespace std;
bool isPrime[1000001];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // 아리스토텔레스의 체로 소수 미리 계산
    fill(isPrime, isPrime + 1000001, true);
    for(int i=2; i<=1000; i++)
    {
        int mul = 2;
        while(i*mul < 1000001){
            isPrime[i*mul] = false;
            mul++;
        }
    }
    // for(int i=0; i<20; i++)
    // {
    //     cout << i << ": " << isPrime[i]<< "\n";
    // }
    // 투포인터로 검증 홀수만 뛰어다니면서
    while(true)
    {
        int n;
        cin >> n;
        if(n==0) break;
        
        int a = 3;
        int b = n-a;
        while(true)
        {
            if(a > b){
                cout << "Goldbach's conjecture is wrong.\n";
                break;
            }
            if(isPrime[a] && isPrime[b]){
                cout << n << " = " << a << " + " << b << "\n";
                break;
            }
            a+=2;
            b-=2;
        }
    }
}