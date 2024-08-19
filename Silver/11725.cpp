#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> graph;
vector<int> visited;
vector<int> parents;

void DFS(int cur)
{
    visited[cur] = 1;
    for(auto adj: graph[cur])
    {
        if(visited[adj] == 0)
        {
            parents[adj] = cur;
            DFS(adj);
        }
    }
}

int main()
{
    int N;
    cin >> N;
    graph.resize(N+1, vector<int>(0));
    visited.resize(N+1, 0);
    parents.resize(N+1, 0);

    for(int i=0; i<N-1; i++)
    {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    DFS(1);
    for(int i=2; i<=N; i++){
        cout << parents[i] << "\n";
    }
}