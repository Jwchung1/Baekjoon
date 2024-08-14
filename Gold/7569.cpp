#include <iostream>
#include <queue>
using namespace std;

typedef struct Trip{
    int first;
    int second;
    int third;

    Trip(int a, int b, int c)
    {
        first = a;
        second = b;
        third = c;
    }
} Trip;

int M,N,H;
int box[100][100][100]; // 높이, 행, 열 순서
Trip dir[6] = {Trip(1,0,0), Trip(-1,0,0), Trip(0,1,0), Trip(0,-1,0), Trip(0,0,1), Trip(0,0,-1)};

queue<Trip> q1;
queue<Trip> q2;
int ripe_tomato = 0;
int total_tomato = 0;

bool IsValid(Trip t)
{
    if(t.first < 0 || t.second < 0 || t.third < 0 || t.first >= H || t.second >= N || t.third >= M) return false;
    return true;
}

int main()
{
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    cin >> M >> N >> H;
    for(int h=0; h<H; h++)
    {
        for(int n=0; n<N; n++)
        {
            for(int m=0; m<M; m++)
            {
                cin >> box[h][n][m];
                if(box[h][n][m] == 1)
                {
                    ripe_tomato++;
                    total_tomato++;
                    q1.push(Trip(h,n,m));
                }
                else if(box[h][n][m] == 0) total_tomato++;
            }
        }
    }
    
    int days = 0;
    while(true)
    {
        if(q1.empty() && q2.empty()) break;
        if(ripe_tomato == total_tomato) break;

        if(q2.empty())
        {
            // q1에서 돌면서 q2에 넣기
            while(!q1.empty())
            {
                Trip cur = q1.front();
                q1.pop();
                for(int i=0; i<6; i++)
                {
                    Trip next = Trip(cur.first + dir[i].first, cur.second + dir[i].second, cur.third + dir[i].third);
                    if(IsValid(next) && box[next.first][next.second][next.third] == 0)
                    {
                        box[next.first][next.second][next.third] = 1;
                        q2.push(next);
                        ripe_tomato++;
                    }
                }
            }
        }
        else
        {
            // q2에서 돌면서 q1에 넣기
            while(!q2.empty())
            {
                Trip cur = q2.front();
                q2.pop();
                for(int i=0; i<6; i++)
                {
                    Trip next = Trip(cur.first + dir[i].first, cur.second + dir[i].second, cur.third + dir[i].third);
                    if(IsValid(next) && box[next.first][next.second][next.third] == 0)
                    {
                        box[next.first][next.second][next.third] = 1;
                        q1.push(next);
                        ripe_tomato++;
                    }
                }
            }
        }
        days++;
    }
    if(ripe_tomato != total_tomato) days = -1;
    cout << days;
}