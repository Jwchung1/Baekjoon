#include <iostream>
using namespace std;
int N, M;
int graph[1001][1001] = {0,};
int visited[1001] = {0,};
int answer = 0;
void DFS(int cur)
{   
    visited[cur] = 1;
    for(int i=1; i<=N; i++)
    {
        if(visited[i] == 0 && graph[cur][i] == 1)
        {
            // 연결돼있고 간 적 없으면 방문
            DFS(i);
        }
    }
}

int main()
{
    cin >> N >> M;
    while(M--)
    {
        int u, v;
        cin >> u >> v;
        graph[u][v] = 1;
        graph[v][u] = 1;
    }
    for(int i=1; i<=N; i++)
    {
        if(visited[i] == 0){
            answer++;
            DFS(i);
        }
    }
    cout << answer;
}