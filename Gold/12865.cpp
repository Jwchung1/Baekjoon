// ********DP식 세우기 어려운 문제. 하지만 중요한듯 0-1 Knapsack 문제

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, K;
vector<pair<int,int>> items;
int DP[101][100001]; // DP[i][j] = i번까지의 아이템을 이용해서 j무게의 가방을 채울수 있는 가치최대값
int main()
{
    cin >> N >> K;
    items.push_back({0,0}); // dummy item
    for(int i=0; i<N; i++)
    {
        int W, V;
        cin >> W >> V;
        pair<int,int> item = make_pair(W,V);
        items.push_back(item);
    }

    sort(items.begin(), items.end());

    for(int i=1; i<=N; i++)
    {
        for(int j=1; j<=K; j++)
        {
            int val_i = items[i].second;
            int weight_i = items[i].first;
            if(weight_i <= j)
            {
                // i번째 아이템이 가방에 들어갈 수 있으면
                //           i번째 아이템 넣는 경우,           안 넣는 경우
                DP[i][j] = max(DP[i-1][j - weight_i] + val_i, DP[i-1][j]);
            }
            else
            {
                // 안 들어가면
                DP[i][j] = DP[i-1][j];
            }
        }
    }
    cout << DP[N][K];
}