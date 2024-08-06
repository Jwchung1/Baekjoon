#include <iostream>
#include <queue>
using namespace std;

int M, N;
int box[1000][1000];
int tomato_num = 0; // 총 토마토 개수
int ripe_tomato_num = 0; // 익은 토마토 개수
int days = 0;
pair<int,int> dir[4] = {{0,1},{0,-1},{1,0},{-1,0}};
queue<pair<int,int>> q1, q2;

bool IsValidPos(pair<int,int> p)
{
    if(p.first < 0 || p.first >= N || p.second < 0 || p.second >= M) return false;
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> M >> N;
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<M; j++)
        {
            cin >> box[i][j];
            if(box[i][j] != -1)
            {
                tomato_num++;
                if(box[i][j] == 1)
                {
                    q1.push(make_pair(i,j));
                }
            }
        }
    }
    while(true)
    {
        if(q1.empty() && q2.empty()) break;
        else
        {
            if(q1.empty())
            {
                // q1에 다음 순회할 점들 넣을거
                while(!q2.empty())
                {
                    pair<int,int> cur = q2.front();
                    ripe_tomato_num++;
                    q2.pop();
                    for(int i=0; i<4; i++)
                    {
                        pair<int,int> next = {cur.first + dir[i].first, cur.second + dir[i].second};
                        if(IsValidPos(next))
                        {
                            if(box[next.first][next.second] == 0)
                            {
                                box[next.first][next.second] = 1;
                                q1.push(next);
                            } 
                        }
                    }
                }
            }
            else
            {
                // q2에 다음 순회할 점들 넣을거
                while(!q1.empty())
                {
                    pair<int,int> cur = q1.front();
                    ripe_tomato_num++;
                    q1.pop();
                    for(int i=0; i<4; i++)
                    {
                        pair<int,int> next = {cur.first + dir[i].first, cur.second + dir[i].second};
                        if(IsValidPos(next))
                        {
                            if(box[next.first][next.second] == 0)
                            {
                                box[next.first][next.second] = 1;
                                q2.push(next);
                            } 
                        }
                    }
                }
            }
            if(tomato_num == ripe_tomato_num) break;
            days++;
        }  
    }
    if(ripe_tomato_num != tomato_num) days = -1;
    cout << days;
}