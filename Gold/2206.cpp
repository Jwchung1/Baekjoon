// 나중에 다시 보기 **
// 메모리 초과 뜬 이유는  else if(visited[next.first][next.second][0] == 0) 이 조건 없이 그냥 else로 처리해서 q에 계속 담겨서 그럼
// C++에서는 배열 인덱스 범위 런타임에 체크 안함. 따라서 에러 안남.
// -> undefined behavior
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N,M;
pair<int,int> dir[4] = {{0,1},{0,-1},{1,0},{-1,0}};
int visited[1000][1000][2]; // 0:벽 안부수고 간거, 1:벽부수고 간거

bool IsValid(pair<int,int> p)
{
    if(p.first < 0 || p.first >= N || p.second < 0 || p.second >= M) return false;
    return true;
}

int BFS()
{
    queue<pair<pair<int,int>, bool>> q;
    q.push({{0,0},false});
    while(!q.empty())
    {
        pair<int,int> cur = q.front().first;
        bool IsWallBroken = q.front().second;
        q.pop();
        // 도착했으면 탈출
        if(cur.first == N-1 && cur.second == M-1){
            for(int i=0; i<N;i++)
            {
                for(int j=0; j<M; j++)
                {
                    cout << visited[i][j][0] << " ";
                }
                cout << "\n";
            }
            cout << "\n";
            for(int i=0; i<N;i++)
            {
                for(int j=0; j<M; j++)
                {
                    cout << visited[i][j][1] << " ";
                }
                cout << "\n";
            }
            // 현 위치를 벽 깨고 왔으면 visited[n-1][m-1][1], 안 깨고 왔으면 visited[n-1][m-1][0] 당연한것,
            return visited[N-1][M-1][IsWallBroken] + 1;
        } 

        for(int i=0; i<4; i++)
        {
            pair<int,int> next = {cur.first + dir[i].first, cur.second + dir[i].second};
            if(IsValid(next))
            {
                // 다음 위치가 벽이면
                if(visited[next.first][next.second][0] == 1)
                {   // 벽을 더 깰 수 있는지 확인하고
                    if(!IsWallBroken)
                    {   // 더 깰 수 있으면 깨고 들어간다. 벽깨고간 거리 = 벽 안깨고간 거리 + 1
                        visited[next.first][next.second][1] = visited[cur.first][cur.second][0] + 1;
                        q.push({next,true});
                    }
                }
                // 다음 위치가 벽이 아니면 (벽 안 깨고 간적이 없으면)(이미 방문한 경우를 배제하는 조건문인거)
                else if(visited[next.first][next.second][0] == 0) // == 0 조건이어야 하는 이유는, 거리를 저장하고 있기 때문에, 그냥 else는 갔던 곳 또갈 수 있음.
                {   // 벽을 깨고 왔는데, 다음 위치 벽 깨고 간 자리가 이미 간적이 있으면 스킵 그것보다 짧아질 수 없으니까.
                    if(IsWallBroken && visited[next.first][next.second][IsWallBroken]) continue;
                    // 다음 위치가 벽이 아니니까, IsWallBroken은 변함 없이 유지. 거리 갱신도 IsWallBroken에 일관되게
                    // 벽을 깨고 왔으면 다음 위치도 벽을 깨고간게 되는거고, 안 깨고 왔으면 다음 위치도 안 깨고간게 되는거니까
                    visited[next.first][next.second][IsWallBroken] = visited[cur.first][cur.second][IsWallBroken] + 1;
                    q.push({next, IsWallBroken});
                }
            }
        }
    }
    return -1;
}

int main()
{
    cin >> N >> M;
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<M; j++)
        {
            char tmp;
            cin >> tmp;
            visited[i][j][0] = tmp - '0';
        }
    }
    cout << BFS();
}