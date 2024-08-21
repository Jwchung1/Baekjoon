#include <iostream>
using namespace std;
int Map[1001][1001];
int main()
{
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    int N, M, X;
    cin >> N >> M >> X;
    for(int i=1; i<=N; i++)
    {
        for(int j=1; j<=N; j++)
        { 
            if(i==j) Map[i][j] = 0;
            else Map[i][j] = 1000000;
        }
    }
    for(int i=0; i<M; i++)
    {
        int s,e,t;
        cin >> s >> e >> t;
        Map[s][e] = t;
    }
    //플로이드 알고리즘
    for(int k=1; k<=N; k++)
    { // k는 거쳐가는 마을
        for(int i=1; i<=N; i++)
        {
            for(int j=1; j<=N; j++)
            { // i번 마을에서 j번 마을로 가는데, k를 거쳐서 가는게 최단경로니?
                if(Map[i][k] != 1000000 && Map[k][j] != 1000000) // i->k , k->j 길이 존재해야함 일단
                {
                    Map[i][j] = min(Map[i][j], Map[i][k] + Map[k][j]);
                }
            }
        }
    }
    int max_dist = 0;
    for(int i=1; i<=N; i++)
    {
        max_dist = max(max_dist, Map[i][X] + Map[X][i]);
    }
    cout << max_dist;
}