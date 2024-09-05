#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int A[51][51];
int visited[51][51];
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
int N, L, R;
bool isUnion = false;

void debug()
{
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            cout << A[i][j] << " ";
        }
        cout << "\n";
    }
}

void BFS(pair<int,int> start)
{
    //cout << "start:" << start.first << start.second << "\n";
    int unionNum = 0;
    int unionSum = 0;
    visited[start.first][start.second] = 1;
    queue<pair<int,int>> q, unionMembers;
    q.push(start); unionMembers.push(start);

    while(!q.empty())
    {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();
        for(int i=0; i<4; i++)
        {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if(nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
            if(visited[nx][ny] == 1) continue;
            else
            {
                int popDiff = abs(A[nx][ny] - A[cx][cy]);
                if(popDiff <= R && popDiff >= L)
                {
                    unionNum++;
                    unionSum += A[nx][ny];
                    visited[nx][ny] = 1;
                    unionMembers.push({nx,ny});
                    q.push({nx,ny});
                }
            }
        }
    }
    if(unionNum > 0)
    {
        isUnion = true;
        unionNum++;
        unionSum += A[start.first][start.second];
        int newPop = unionSum / unionNum;
        while(!unionMembers.empty())
        {
            A[unionMembers.front().first][unionMembers.front().second] = newPop;
            unionMembers.pop();
        }
    }
    //cout << "unionnum, unionsum:" << unionNum << "," <<unionSum << "\n";
}

int main()
{
    cin >> N >> L >> R;
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            cin >> A[i][j];
        }
    }
    int days = 0;
    while(true)
    {
        memset(visited, 0, sizeof(visited));
        isUnion = false;
        // 국경 열기
        for(int i=0; i<N; i++)
        {
            for(int j=0; j<N; j++)
            {
                if(visited[i][j] == 0)
                {
                    BFS({i,j});
                }
            }
        }
        if(!isUnion) break;
        days++;
    }
    cout << days;
}