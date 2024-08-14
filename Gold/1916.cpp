// ********************중요한 문제
// INT32_MAX = int형 , INT64_MAX = long long int 형. 
// int a = INT64_MAX 하면 오버플로우 나서 -1됨
// 다익스트라 최소 거리 찾기 문제.
// adj는 링크드리스트로 표현. vector<vector<pair<int,int>>> adj;
// dist는 1차원 벡터로 표현. start에서 i지점까지의 거리 담음
// visited는 decreasekey를 대체하기 위해 사용. 방문한 곳인지 체크 후, 스킵
// priority_queue는 pair<cost, dest>로 cost순으로 오름차순 정렬
// queue 초기화시, start노드만 push (decreasekey를 안쓰기 때문)
// 벡터 동적할당 방법: v.resize(크기, 초기화값)


#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int N, M;
int start, dest;

vector<vector<pair<int,int>>> adj; // 연결된 간선 linked list {cost, dest};
vector<int> dist; // 시작지점에서 i 노드 까지의 거리
vector<bool> visited;

priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q; // {cost, dest};

void Dijkstra()
{
    dist[start]= 0;
    q.push({0,start});
    
    while(!q.empty())
    {
        int cur_cost = q.top().first; // 현재 있는 노드까지 오는데 든 비용
        int cur_pos = q.top().second; // 현재 있는 노드
        q.pop();

        if(visited[cur_pos]) continue;
        visited[cur_pos] = true;
        
        for(auto edge : adj[cur_pos])
        {
            if(dist[edge.second] > cur_cost + edge.first)
            {
                dist[edge.second] = cur_cost + edge.first;
                q.push({dist[edge.second], edge.second});
            }
        }
    }
    cout << dist[dest];
}

int main()
{
    cin >> N >> M;
    adj.resize(N+1);
    dist.resize(N+1, INT32_MAX);
    visited.resize(N+1, false);
    while(M-- > 0)
    {
        int s, d, c;
        cin >> s >> d >> c;
        adj[s].emplace_back(c,d);
    }
    cin >> start >> dest;
    Dijkstra();
}