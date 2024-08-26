// MST 문제

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct cmp{
    bool operator()(pair<pair<int,int>,int> e1, pair<pair<int,int>,int> e2){
        return e1.second > e2.second;
    }
};

priority_queue<pair<pair<int,int>,int>, vector<pair<pair<int,int>,int>>, cmp> reachable_edges; // (시점, 종점), 가중치
vector<vector<pair<int,int>>> graph;
vector<int> visited;
int MST_weight = 0;
void MST()
{
    // 1번부터시작
    visited[1] = 1;
    for(auto edge : graph[1]){
        reachable_edges.push({{1, edge.first},edge.second});
    }
    while(!reachable_edges.empty())
    {
        pair<pair<int,int>,int> cur_edge = reachable_edges.top();
        int cur_pos = cur_edge.first.second;
        reachable_edges.pop();
        if(visited[cur_pos] == 1) continue;
        MST_weight += cur_edge.second;
        visited[cur_pos] = 1;
        for(auto edge : graph[cur_pos]){
            reachable_edges.push({{cur_pos, edge.first},edge.second});
        }
    }
    cout << MST_weight;    
}

int main()
{
    int V,E;
    cin >> V >> E;
    graph.resize(V+1);
    visited.resize(V+1, 0);
    for(int i=0; i<E; i++)
    {
        int a,b,c;
        cin >> a >> b >> c;
        graph[a].push_back({b,c});
        graph[b].push_back({a,c});
    }
    MST();
}