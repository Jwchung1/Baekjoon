#include <iostream>
using namespace std;
int Map[502][502];
int DP[502][502];
int main()
{
    int M,N;
    cin >> M >> N;
    for(int i=1; i<=M; i++)
    {
        for(int j=1; j<=N; j++)
        {
            cin >> Map[i][j];
        }
    }
    DP[1][1] = 1;
    bool Changed = true;
    while(Changed)
    {
        Changed = false;
        for(int i=1; i<=M; i++)
        {
            for(int j=1; j<=N; j++)
            {
                int old_sum = DP[i][j];
                int new_sum = 0;
                if(Map[i-1][j] > Map[i][j]) new_sum+=DP[i-1][j];
                if(Map[i+1][j] > Map[i][j]) new_sum+=DP[i+1][j];
                if(Map[i][j-1] > Map[i][j]) new_sum+=DP[i][j-1];
                if(Map[i][j+1] > Map[i][j]) new_sum+=DP[i][j+1];
                if(i==1 && j==1) continue;
                else{
                    DP[i][j] = new_sum;
                }
                if(old_sum != new_sum) Changed = true;
            }
        }
    }
    cout << DP[M][N];
}