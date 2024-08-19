#include <iostream>
#include <queue>
using namespace std;

int n,m;
int map[1001][1001];
int visited[1001][1001] = {0,};
pair<int,int> dest;
pair<int,int> dir[4] = {{0,1},{0,-1},{1,0},{-1,0}};

bool IsValid(pair<int,int> p)
{
    if(p.first < 0 || p.second < 0 || p.first >= n || p.second >= m || map[p.first][p.second] == 0) return false;
    return true;
}

void BFS()
{
    queue<pair<int,int>> q;
    q.push(dest);
    visited[dest.first][dest.second] = 1;
    while(!q.empty())
    {
        pair<int,int> cur = q.front();
        q.pop();
        for(auto d : dir){
            pair<int,int> next = {cur.first + d.first, cur.second + d.second};
            if(IsValid(next) && visited[next.first][next.second] == 0){
                // 거리 갱신
                map[next.first][next.second] = map[cur.first][cur.second] + 1;
                // 방문 체크
                visited[next.first][next.second] = 1;
                q.push(next);
            }
        }
    }
}

int main()
{
    cin >> n >> m;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            int ground;
            cin >> ground;
            if(ground == 2) {
                dest = {i,j};
                ground = 0;
            }
            else if(ground != 0) ground = -1;
            map[i][j] = ground;
        }
    }
    map[dest.first][dest.second] = 0;
    BFS();
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cout << map[i][j] << " ";
        }
        cout << "\n";
    }
}