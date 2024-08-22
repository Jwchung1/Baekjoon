// 벨만포드 알고리즘으로 Negative cycle을 찾는 문제.
// 본래 벨만포드 알고리즘은 특정한 시작점 a에서 출발했을때, negative cycle이 존재하는지를 확인할 수 있다.
// 하지만 이 문제에서는 모든 시작점에 대해 negative cycle이 하나라도 존재하면 YES를 출력하는 문제이다.
// 모든 시작점에 대해 따로 벨만포드를 적용하면 시간초과가 뜬다.
// 따라서 본래 if(Dist[from] == INF) continue; 이 조건이 있어야 하지만, 이게 있으면 한 정점에서 출발했을때 그 정점과 이어져 있지 않은 단절된 그래프에서 cycle이 형성된 경우를 찾을 수 없다.
// 사이클 유무만 판단할 때는 Dist[]를 어떤 값으로 초기화해도 상관이 없다. 변화가 되는지만 확인하면 되기 때문.
// ***중요한 문제*** 벨만포드 기억하자!!

#include <iostream>
#include <vector>
#define INF 10000000
using namespace std;
int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        int N,M,W;
        cin >> N >> M >> W;
        // 최단거리 초기화
        vector<int> Dist;
        Dist.resize(N+1, INF);
        Dist[1] = 0;
        vector<pair<pair<int,int>,int>> edges;
        // 입력
        for(int i=0; i<M; i++)
        {
            int S,E,T;
            cin >> S >> E >>T;
            edges.push_back({{S,E},T});
            edges.push_back({{E,S},T});
        }
        for(int i=0; i<W; i++)
        {
            int S,E,T;
            cin >> S >> E >>T;
            edges.push_back({{S,E},-T});
        }
        // 벨만포드 알고리즘
        for(int i=1; i<=N-1; i++)
        { // 모든 edge relax를 N-1번 하겠다는거
            for(int j=0; j<edges.size(); j++)
            { // 모든 edge relax
                int from = edges[j].first.first;
                int to = edges[j].first.second;
                int cost = edges[j].second;
                //if(Dist[from] == INF) continue; // 계산된적 있는 정점에서 출발하는 경우만 계산 하지만, 이 문제에선 없어야함. 
                if(Dist[to] > Dist[from] + cost) Dist[to] = Dist[from] + cost;
            }
        }
        // 여기서 한번 더 모든 edge relax 했는데, 갱신이 발생하면 negative cycle 존재
        bool isNegCycle = false;
        for(int j=0; j<edges.size(); j++)
        { // 모든 edge relax
            int from = edges[j].first.first;
            int to = edges[j].first.second;
            int cost = edges[j].second;
            if(Dist[to] > Dist[from] + cost) {
                isNegCycle = true;
                break;
            }
        }
        if(isNegCycle) cout << "YES\n";
        else cout << "NO\n";
    }
}
