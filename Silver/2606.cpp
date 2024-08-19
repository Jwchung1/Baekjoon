// DFS 그래프 탐색 문제. BFS도 될듯 (DAG가 아니라 양방향이 가능했던게 포인트)

#include <iostream>
#include <vector>

using namespace std;
int V, E;
int graph[101][101] = {0,};
vector<int> visited;
int answer = 0;

void DFS(int cur)
{
    visited[cur] = 1;
    for(int i=1; i<=V; i++)
    {
        if(graph[cur][i] == 1 && visited[i] == 0)
        { // 간선이 있고 안 간곳만 감
            DFS(i);
        }
    }
    answer++;
    return;
}
int main()
{
    
    cin >> V >> E;

    visited.resize(V+1, 0);
    while(E-- > 0)
    {
        int v1,v2;
        cin >> v1 >> v2;
        graph[v1][v2] = 1;
        graph[v2][v1] = 1;
    }
    DFS(1);
    cout << answer - 1;
}