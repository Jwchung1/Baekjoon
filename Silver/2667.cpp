// visited를 언제 갱신하는 지도 중요 포인트!

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N;
int cluster_count = 0;
int house_count[313];

int visited[25][25] = {0,};
vector<string> map;
pair<int, int> direction[4] = {{1,0}, {-1,0}, {0,1}, {0,-1}};

void BFS(int i, int j)
{
    queue<pair<int,int>> q;
    q.push(pair(i, j));
    int cnt = 0;
    visited[i][j] = 1;

    while(!q.empty())
    {
        cnt++;
        pair<int, int> cur_pos = q.front();
        q.pop();

        for(int i=0; i<4; i++)
        {
            pair<int, int> next_pos = {cur_pos.first + direction[i].first, cur_pos.second + direction[i].second};
            if(next_pos.first >= 0 && next_pos.first < N && next_pos.second >= 0 && next_pos.second < N && visited[next_pos.first][next_pos.second] == 0 && map[next_pos.first][next_pos.second] == '1')
            {
                visited[next_pos.first][next_pos.second] = 1;
                q.push(next_pos);
            }
        }
    }
    house_count[cluster_count++] = cnt;
}

int main()
{
    cin >> N;
    for(int i=0; i<N; i++)
    {
        string tmp;
        cin >> tmp;
        
        map.push_back(tmp);
    }

    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            if(map[i][j] != '0' && visited[i][j] == 0)
            {
                // 집이면서, 방문한적 없는 집이면 bfs 실행
                BFS(i,j);
            }
        }
    }

    cout << cluster_count << "\n";
    sort(house_count, house_count + cluster_count);
    for(int i=0; i<cluster_count; i++)
    {
        cout << house_count[i] << "\n";
    }
}
