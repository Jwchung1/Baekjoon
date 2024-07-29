// DFS, BFS 문제. DFS의 구현유형을 잘 알아두자 재귀가 아니라 반복문으로 구현하는 연습

#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;

int dfs_graph[1001][1001] = {0,};
int bfs_graph[1001][1001] = {0,};

int dfs_visited[1001] = {0,};
int bfs_visited[1001] = {0,};
int N, M, V;

void DFS()
{
    stack<int> s; // 정점 번호를 담은 스택
    s.push(V);
    dfs_visited[V] = 1;
    cout << V << " ";
    while(!s.empty())
    {
        int cur_vertex = s.top();
        int flag = 0;
        for(int i=1; i<=N; i++)
        {
            int isConnected = dfs_graph[cur_vertex][i]; // 현재 정점이 i번 정점과 연결돼있는지
            if(isConnected == 1 && dfs_visited[i] != 1)
            {
                // 연결돼있으면서 한번도 안간곳이면 스택에 추가
                cout << i << " ";
                dfs_visited[i] = 1;
                s.push(i);
                flag = 1;
                break; // DFS는 하나만 파는거라 여러개를 스택에 담지 않음
            }
        }
        if(flag == 0) s.pop(); // 해당 정점에서 더 이상 갈 곳이 없으면 스택에서 뽑기
    }
}

void BFS()
{
    queue<int> q;
    q.push(V);
    bfs_visited[V] = 1;

    while(!q.empty())
    {
        int cur_vertex = q.front();
        q.pop();
        cout << cur_vertex << " ";
        for(int i=1; i<=N; i++)
        {
            int isConnected = bfs_graph[cur_vertex][i];
            if(isConnected == 1 && bfs_visited[i] != 1)
            {
                bfs_visited[i] = 1;
                q.push(i);
            }
        }
    }
}

int main()
{
    cin >> N >> M >> V;

    for(int i=0; i<M; i++)
    {
        int v1, v2;
        cin >> v1 >> v2;
        dfs_graph[v1][v2] = 1;
        dfs_graph[v2][v1] = 1;
    }
    copy(&dfs_graph[0][0], &dfs_graph[0][0] + 1001*1001, &bfs_graph[0][0]);

    DFS();
    cout << "\n";
    BFS();
}
