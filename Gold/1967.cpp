// 트리는 방향 없는 그래프로 표현한다.
// 노드마다 연결된 노드가 링크드리스트로 존재하게 하는데, 양방향으로 graph[a].push_back(b) , graph[b].push_back(a)

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<vector<pair<int,int>>> graph; // graph[i]에는 연결된 노드정보가 {cost, dest} 으로 저장된다
int visited[10001] = {0,}; // 자식에서 부모 올라오는거 막는 용도
int weight[10001]; // i노드에서 한쪽팔로 뻗는 가장 긴 길이
int answer = 0;
int n;

void DFS(int cur)
{
    visited[cur] = 1;
    vector<int> weights;
    weights.clear();
    for(auto adj: graph[cur])
    {
        if(visited[adj.second] == 0)
        {
            DFS(adj.second);
            weight[cur] = max(weight[cur], adj.first + weight[adj.second]);
            weights.push_back(adj.first + weight[adj.second]);
        } 
    }
    sort(weights.begin(), weights.end(), greater<int>());
    int weight_fir = 0;
    int weight_sec = 0;
    if(!weights.empty())
    {
        if(weights.size() == 1) weight_fir = weights[0];
        else{
            weight_fir = weights[0];
            weight_sec = weights[1];
        } 
    }
    answer = max(weight_fir + weight_sec, answer);
}

int main()
{
    cin >> n;
    graph.resize(n+1);
    for(int i=0; i<n-1; i++)
    {
        int a,b,c;
        cin >> a >> b >> c;
        graph[a].push_back({c,b});
        graph[b].push_back({c,a});
    }
    DFS(1);
    cout << answer;
}