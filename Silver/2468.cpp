// 반례 하나 때문에 틀렸던 BFS 석유시추 유형. 모든 2차원 배열 지점에 한번씩 BFS를 실행해줘야한다. 
// 이때, 이미 이전 BFS로 방문한 지역은 다시 갈 필요 없으므로, 사실상 BFS는 지도를 지도 크기만큼 순회하게된다. 
// 틀린 이유: h=1부터 순회해서 틀렸다. h=0부터 하면 맞는다.

#include <iostream>
#include <queue>

using namespace std;

int N;
int map[100][100];
int visited[100][100] = {0,};
pair<int,int> dir[4] = {{1,0},{-1,0},{0,1},{0,-1}}; 
int max_safe_zone = 0;
int max_ground_height = 0;

bool IsValidPos(pair<int,int> p)
{  
    if(p.first < 0 || p.second < 0 || p.first >= N || p.second >= N) return false;
    return true;
}

int BFS(int rain_height, pair<int,int> start_pos)
{
    queue<pair<int,int>> q;
    q.push(start_pos);
    int zone_size = 0;
    while(!q.empty())
    {
        pair<int,int> cur_pos = q.front();
        q.pop();
        zone_size++;
        for(int i=0; i<4; i++)
        {
            pair<int,int> next_pos = make_pair(cur_pos.first + dir[i].first, cur_pos.second + dir[i].second);
            if(IsValidPos(next_pos) && visited[next_pos.first][next_pos.second] == 0 && map[next_pos.first][next_pos.second] > rain_height)
            {
                // 유효한 곳이면서 갔던 곳이 아니면서 잠기는 곳이 아니면 방문
                visited[next_pos.first][next_pos.second] = 1;
                q.push(next_pos);
            }
        }
    }

    if(zone_size > 0) return 1;
    return 0;
}

int main()
{
    cin >> N;
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            cin >> map[i][j];
            max_ground_height = max(max_ground_height, map[i][j]);
        }
    }
    
    for(int h=0; h<max_ground_height; h++)
    {
        int safe_zone_num = 0;
        for(int i=0; i<N; i++)
        {
            for(int j=0; j<N; j++)
            {
                if(map[i][j] > h && visited[i][j] == 0)
                {
                    safe_zone_num += BFS(h, make_pair(i,j));
                }
            }
        }
        for(int i=0; i<N; i++)
        {
            for(int j=0; j<N; j++)
            {
                visited[i][j] = 0;
            }
        }
        max_safe_zone = max(max_safe_zone, safe_zone_num);
    }
    cout << max_safe_zone;
}