#include <iostream>

using namespace std;

int T,N,M;
int DP[31][31]; // i개를 j개와 잇는 경우의 수
int main()
{
    cin >> T;
    for(int i=0; i<31; i++)
    {
        DP[i][i] = 1;
        DP[0][i] = 1;
    }
    while(T-- > 0)
    {
        cin >> N >> M;

        for(int i=1; i<=N; i++)
        {
            for(int j=i+1; j<=M; j++)
            {
                DP[i][j] = DP[i][j-1] + DP[i-1][j-1];
            }
        }

        cout << DP[N][M] << "\n";
    }

}