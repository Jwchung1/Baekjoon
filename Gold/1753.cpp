#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int V,E,K;
vector<vector<pair<int,int>>> graph; // graph[i]: i와 연결된 간선들의 벡터. 간선: {cost, dest}
vector<int> dist_from_start; // start로부터 i까지의 거리
vector<int> visited; // decrease_key 안 쓰고 visited체크 후 방문 안한곳만 계산할거임
priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q; // 방문해야하는 정점들 cost 순으로 정렬

void Dijkstra(int start)
{
    dist_from_start[start] = 0;
    for(int i=1; i<=V; i++)
    {
        q.push(make_pair(dist_from_start[i], i)); // queue에 모든 노드 넣기
    }
    // 알고리즘 시작
    while(!q.empty())
    {
        int cur_cost = q.top().first; // 현위치까지 오는데 든 비용
        int cur_pos = q.top().second; // 현위치
        q.pop();
        if(visited[cur_pos] == 1) continue; // 이미 왔던 곳이면 패스
        visited[cur_pos] = 1; // 현위치 방문 표시
        //cout << cur_cost << ", " << cur_pos << "\n";
        for(auto adj : graph[cur_pos])
        {
            //cout << cur_pos << " adj: " << adj.first << "\n";
            int adj_cost = adj.first; // 인접위치로 가는데 드는 간선 비용
            int adj_pos = adj.second; // 인접위치
            if(dist_from_start[adj_pos] > adj_cost + cur_cost)
            {
                // 거리가 더 짧아질수 있으면 갱신
                //printf("dist_from_start[%d] = %d + %d\n", adj_pos, adj_cost, cur_cost);
                dist_from_start[adj_pos] = adj_cost + cur_cost;
                q.push({dist_from_start[adj_pos], adj_pos});
            }
        }
    }
}

int main()
{
    cin >> V >> E >> K;
    // 그래프 생성
    graph.resize(V+1);
    for(int i=0; i<E; i++)
    {
        int u,v,w;
        cin >> u >> v >> w;
        graph[u].emplace_back(make_pair(w,v));
    }
    dist_from_start.resize(V+1, 1000000); // 이거 INF 수치를 몇으로 잡아야할까? INT32_MAX는 오버플로우 다뤄야되는데, 오버플로우 안나면서 적당히 큰 숫자는 몇으로..?
    visited.resize(V+1, 0);
    Dijkstra(K);
    for(int i=1; i<=V; i++)
    {
        if(dist_from_start[i] == 1000000) cout << "INF\n";
        else cout << dist_from_start[i] << "\n";
    }
}