#include <iostream>
#include <vector>
using namespace std;
int N;
int grid[101][101];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,-1,0,1};

void MakeCurve(int x, int y, int d, int g)
{
    vector<pair<int,int>> v; 
    v.clear();
    grid[x][y] = 1;
    grid[x+dx[d]][y+dy[d]] = 1;
    v.push_back({x,y});
    v.push_back({x+dx[d], y+dy[d]});
    
    for(int i=1; i<=g; i++)
    {
        int ox = v.back().first;
        int oy = v.back().second;
        // o랑 가까운 점부터 돌려야 다음 끝점이 v의 마지막으로 온다.
        for(int i = v.size() - 2; i>=0; i--)
        {
            // p점을 o점 기준 90도 돌려서 v에 저장하고 grid에 표시
            pair<int,int> p = v[i];
            int px = p.first;
            int py = p.second;
            int delta_x = ox - px;
            int delta_y = oy - py;
            int nx = ox + delta_y;
            int ny = oy - delta_x;

            grid[nx][ny] = 1;
            v.push_back({nx,ny});
        }
    }
    // for(auto p : v)
    // {
    //     cout <<p.first << "," << p.second << " ";
    // }
    // for(int i=0; i<=10; i++)
    // {
    //     for(int j=0; j<=10; j++)
    //     {
    //         cout << grid[i][j];
    //     }
    //     cout << "\n";
    // }
}

void CountSquare()
{
    int cnt = 0;
    for(int i=0; i<100; i++)
    {
        for(int j=0; j<100; j++)
        {
            if(grid[i][j] == 1 && grid[i+1][j] == 1 && grid[i][j+1] == 1 && grid[i+1][j+1] == 1) cnt++;
        }
    }
    cout << cnt;
}

int main()
{
    cin >> N;
    for(int i=0; i<N; i++)
    {
        int x,y,d,g;
        cin >> x >> y >> d >> g;
        MakeCurve(x,y,d,g);
    }
    CountSquare();
}