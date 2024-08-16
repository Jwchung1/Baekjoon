// Topological sort
// DFS() -> 끝나면 result에 추가. -> 역방향 출력

#include <iostream>
#include <vector>

using namespace std;
int N, M;
vector<vector<int>> Graph; // Graph[i] 는 i에 연결된 노드들이 담긴 벡터
vector<int> node_color; // 0: white, 1: gray, 2: black
vector<int> result;

void DFS(int cur)
{
    
    if(Graph[cur].empty())
    {
        // 더 이상 연결된게 없으면,
        result.push_back(cur);
        node_color[cur] = 2;
        return;
    }
    for(auto adj : Graph[cur])
    {
        if(node_color[adj] == 0)
        {
            DFS(adj);
        }
    }
    result.push_back(cur);
    node_color[cur] = 2;
    return;
}

int main()
{
    cin >> N >> M;
    Graph.resize(N+1, vector<int>(0)); // N+1개의 빈 벡터들의 벡터로 초기화
    node_color.resize(N+1, 0);
    for(int i=0; i<M; i++)
    {
        int a, b;
        cin >> a >> b;
        Graph[a].emplace_back(b);
    }
    for(int i=1; i<=N;i++)
    {
        if(node_color[i] == 0)
        {
            DFS(i);
        }
    }
    for(int i=result.size()-1; i>=0; i--)
    {
        cout << result[i] << " ";
    }
}