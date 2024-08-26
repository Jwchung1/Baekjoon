#include <iostream>
using namespace std;
#define MOD 1000000000;
long long DP[101][12] = {0,};
int main()
{
    int N;
    cin >> N;
    DP[10][1] = 1; // 0자리
    DP[10][10] = 1; // 9자리
    long long sum = 0;
    for(int i=11; i<=N; i++){
        for(int j=1; j<=10; j++){
            DP[i][j] = (DP[i-1][j-1] + DP[i-1][j+1])%MOD;
        }
    }
    for(int i=2; i<=10; i++){
        sum += DP[N][i];
        sum %= MOD;
    }
    cout << sum;
}