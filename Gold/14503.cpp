// BFS문제. 이동조건이 좀 이해하기 까다로웠다.

#include <iostream>
#include <queue>

using namespace std;
int N, M;
int r, c, d;
pair<int,int> dir[4] = {{-1,0}, {0,1}, {1,0}, {0,-1}};
int room[50][50] = {0,};

int answer = 0;

bool IsValid(pair<int,int> p)
{
    if(p.first < 0 || p.first >= N || p.second < 0 || p.second >= M || room[p.first][p.second] == 1) return false;
    return true;
}

void BFS(pair<int,int> start)
{
    queue<pair<pair<int,int>,int>> q;
    q.push({start,d});
    while(!q.empty())
    {
        pair<int,int> cur_p = q.front().first;
        int cur_d = q.front().second;
        q.pop();
        if(room[cur_p.first][cur_p.second] == 0)
        {
            room[cur_p.first][cur_p.second] = 2;
            answer++;
        }
        int flag = 0;
        for(int i=cur_d+3; i<cur_d + 13; i+=3)
        {
            pair<int,int> next_p = {cur_p.first + dir[i%4].first, cur_p.second + dir[i%4].second};
            if(IsValid(next_p) && room[next_p.first][next_p.second] == 0)
            {
                flag = 1;
                q.push({next_p, i%4});
                break;
            }
        }
        if(flag == 0)
        {
            pair<int,int> back_p = {cur_p.first - dir[cur_d].first, cur_p.second - dir[cur_d].second};
            if(IsValid(back_p))
            {
                q.push({back_p, cur_d});
            }
            else return;
        }
    }
}

int main()
{
    cin >> N >> M;
    cin >> r >> c >> d;
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<M; j++)
        {
            cin >> room[i][j];
        }
    }
    BFS(make_pair(r,c));
    cout << answer;
    
}