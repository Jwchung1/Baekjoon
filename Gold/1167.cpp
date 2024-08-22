// DFS로 한쪽 끝 찌르고, 올라오면서 올라온 노드의 max_oneway_weight 갱신. 이건 이 노드가 중심이 아닐때, 한쪽팔을 뻗어서 가장 멀리 갈 수 있는 거리
// 한 노드에 달린 모든 팔에 oneway_weight을 구해주고, 팔이 0개면 패스, 팔이 1개면 팔 하나만, 팔이 2개이상이면 max 두개 뽑아서 더한 후, max_radius 갱신.
// max_radius가 결국 정답이됨.
// 요약: 한 노드가 중심이 아닌 경우의 최대로 뻗는 거리와 , 중심인 경우 최대로 양쪽으로 뻗는 거리를 둘다 계산해서 사용한다.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int V;
vector<vector<pair<int,int>>> Tree; // {end, cost}
vector<int> visited;
vector<int> max_oneway_weight;
int max_radius = 0;
void DFS(int cur)
{
    visited[cur] = 1;
    vector<int> tmp_weights;
    tmp_weights.clear();
    for(auto adj: Tree[cur])
    {
        if(visited[adj.first] == 0)
        {
            DFS(adj.first);
            max_oneway_weight[cur] = max(max_oneway_weight[cur], max_oneway_weight[adj.first] + adj.second);
            tmp_weights.push_back(max_oneway_weight[adj.first] + adj.second);
        }
    }
    sort(tmp_weights.begin(), tmp_weights.end(), greater<int>());
    int tmp_max_radius = 0;
    if(!tmp_weights.empty())
    {
        if(tmp_weights.size() == 1) tmp_max_radius = tmp_weights[0];
        else tmp_max_radius = tmp_weights[0] + tmp_weights[1];
    }
    max_radius = max(max_radius, tmp_max_radius);
}

int main()
{
    cin >> V;
    Tree.resize(V+1);
    visited.resize(V+1,0);
    max_oneway_weight.resize(V+1,0);
    for(int i=0; i<V; i++)
    {
        int start;
        cin >> start;
        while(true)
        {
            int end, cost;
            cin >> end;
            if(end == -1){
                break;
            }
            else{
                cin >> cost;
                Tree[start].push_back({end, cost});
            }
        }
    }
    DFS(1);
    cout << max_radius;
}