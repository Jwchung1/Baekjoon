#include <iostream>

using namespace std;
int T;
int DP[16][16]; // n층 i호에 사는 사람 수
int main()
{
    cin >> T;
    for(int i=0; i<=14; i++)
    {
        DP[0][i] = i;
    }
    while(T-- > 0)
    {
        int k, n;
        cin >> k >> n;
        for(int i=1; i<=k; i++)
        {
            for(int j=1; j<=n; j++)
            {
                DP[i][j] = DP[i-1][j] + DP[i][j-1];
            }
        }
        cout << DP[k][n] << "\n";
    }
}