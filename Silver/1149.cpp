#include <iostream>

using namespace std;

int N;
int cost[1000][3] = {0,};
int min_cost[1000][3] = {0,};
int main()
{
    cin >> N;
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<3; j++)
        {
            cin >> cost[i][j];
        }
    }
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<3; j++)
        {
            if(i==0) min_cost[i][j] = cost[i][j];
            int cost1 = min_cost[i-1][(j+1)%3] + cost[i][j];
            int cost2 = min_cost[i-1][(j+2)%3] + cost[i][j];
            min_cost[i][j] = min(cost1, cost2);
        }
    }
    int answer = min(min(min_cost[N-1][0], min_cost[N-1][1]), min_cost[N-1][2]);
    cout << answer;
}
