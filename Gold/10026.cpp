#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

int N;
vector<string> grid;
int visited_CB[101][101];
int visited_N[101][101];
pair<int,int> dir[4] = {{0,1},{0,-1},{1,0},{-1,0}};

int area_CB = 0;
int area_N = 0;

bool IsValid(pair<int,int> p)
{
    if(p.first < 0 || p.first >= N || p.second < 0 || p.second >= N) return false;
    return true;
}

void Colorblind(pair<int,int> start)
{
    queue<pair<int,int>> q;
    q.push(start);
    visited_CB[start.first][start.second] = 1;
    while(!q.empty())
    {
        pair<int,int> cur = q.front();
        q.pop();
        for(int i=0; i<4; i++)
        {
            pair<int,int> next = {cur.first + dir[i].first, cur.second + dir[i].second};
            if(IsValid(next) && visited_CB[next.first][next.second] == 0)
            {
                // 색약 추가조건
                char next_color = grid[next.first][next.second];
                char cur_color = grid[cur.first][cur.second];
                if(next_color == cur_color || (next_color == 'R' && cur_color == 'G') || (next_color == 'G' && cur_color == 'R'))
                {
                    // 같은영역
                    visited_CB[next.first][next.second] = 1;
                    q.push(next);
                }
            }
        }        
    }
    area_CB++;
}

void Normal(pair<int,int> start)
{
    queue<pair<int,int>> q;
    q.push(start);
    visited_N[start.first][start.second] = 1;
    while(!q.empty())
    {
        pair<int,int> cur = q.front();
        q.pop();
        for(int i=0; i<4; i++)
        {
            pair<int,int> next = {cur.first + dir[i].first, cur.second + dir[i].second};
            if(IsValid(next) && visited_N[next.first][next.second] == 0)
            {
                // 정상 추가조건
                char next_color = grid[next.first][next.second];
                char cur_color = grid[cur.first][cur.second];
                if(next_color == cur_color)
                {
                    // 같은영역
                    visited_N[next.first][next.second] = 1;
                    q.push(next);
                }
            }
        }        
    }
    area_N++;
}

int main()
{
    cin >> N;
    for(int i=0; i<N; i++)
    {
        string row;
        cin >> row;
        grid.push_back(row);    
    }
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            if(visited_CB[i][j] == 0) Colorblind({i,j});
            if(visited_N[i][j] == 0) Normal({i,j});
        }
    }
    cout << area_N << " " << area_CB;
}