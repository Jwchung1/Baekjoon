#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<pair<int,int>> tree[40000]; // i번째 노드의 {j노드, dist거리} 

int Dijkstra()
{
    int result;
    
    return result;
}

int main()
{
    cin >> N;
    // 트리 생성
    for(int i=0; i<N; i++)
    {
        int v1, v2, dist;
        cin >> v1 >> v2 >> dist;
        tree[v1].push_back(make_pair(v2,dist));
        tree[v2].push_back(make_pair(v1,dist));
    }

    cin >> M;
    for(int i=0; i<M; i++)
    {
        
    }
}