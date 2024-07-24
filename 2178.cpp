// BFS를 이용한 그래프 탐색 문제
// BFS는 다시 돌아왔을때 더 짧아지지 않는다!

#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;
vector<string> v;
vector<vector<int>> dist;
vector<pair<int,int>> direction = {{0,1},{0,-1},{1,0},{-1,0}};

int main(){

    int N,M;
    cin >> N >> M;
    for(int i=0; i<N; i++)
    {
        string tmp;
        cin >> tmp;
        v.push_back(tmp);
    }

    // dist 초기화
    for(int i=0; i<N; i++)
    {  
        vector<int> tmp;
        for(int j=0; j<M; j++)
        {
            tmp.push_back(-1);
        }
        dist.push_back(tmp);
    }

    // BFS 이용
    queue<pair<int,int>> q;
    pair<int,int> cur_pos = {0,0};
    dist[0][0] = 1;
    q.push(cur_pos);

    while(!q.empty())
    {
        // 현위치 가져오기
        cur_pos = q.front();
        q.pop();
        int cur_distance = dist[cur_pos.first][cur_pos.second];
        // 현위치에서 이동
        for(int i=0; i<4; i++)
        {
            pair<int,int> moved_pos = {direction[i].first + cur_pos.first, direction[i].second + cur_pos.second};
            if(moved_pos.first < 0 || moved_pos.first >= N || moved_pos.second < 0 || moved_pos.second >= M)
            {
                // 그래프 밖임. 큐에 안넣음
                continue;
            }
            else if(v[moved_pos.first][moved_pos.second] == '0')
            {
                // 벽이라서 이동 못함. 큐에 안넣음
                continue;
            }
            else
            {
                int new_distance = dist[moved_pos.first][moved_pos.second];
                // 최단거리로 dist 갱신  || cur_distance + 1 < new_distance 이거 할 필요 없음. BFS는 다시 돌아왔을때 더 짧아지지 않는다!
                // DFS면 다시 왔을때 최단거리일 수 있음!
                if(new_distance == -1)
                {
                    //한번도 안간 곳이기만 하면됨.
                    dist[moved_pos.first][moved_pos.second] = cur_distance + 1;
                    // 다음 탐색 위치로 큐에 넣음
                    q.push(moved_pos);
                }
            }
        }
    }
    cout << dist[N-1][M-1] << endl; 
    return 0;
}
