#include <iostream>
#include <vector>
using namespace std;

int N,M;
vector<vector<int>> Office;
vector<pair<int,int>> cctv;
int answer = 0;

int FindBlindSpot(vector<vector<int>> o)
{
    int ret = 0;
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<M; j++)
        {
            if(o[i][j] == 0) ret++;
        }
    }
    return ret;
}

void Light(int cx, int cy, int dx, int dy, vector<vector<int>>& o) // o에 해당 방향 빛 비춰서 돌려줌
{
    while(1)
    {
        cx = cx + dx;
        cy = cy + dy;
        if(cx < 0 || cx >= N || cy < 0 || cy >= M) break;
        if(o[cx][cy] == 6) break;
        if(o[cx][cy] == 0) o[cx][cy] = 7; // 7이 빛
    }
}

void DFS(int cctvIdx, vector<vector<int>> o)
{
    if(cctvIdx == cctv.size()){
        answer = min(answer, FindBlindSpot(o));
        return;
    }
    int x = cctv[cctvIdx].first;
    int y = cctv[cctvIdx].second;
    int cctvType = Office[x][y];
    vector<vector<int>> no;
    switch(cctvType){
        case 1:
        no = o;
        Light(x,y,1,0,no);
        DFS(cctvIdx+1, no);
        no = o;
        Light(x,y,-1,0,no);
        DFS(cctvIdx+1, no);
        no = o;
        Light(x,y,0,1,no);
        DFS(cctvIdx+1, no);
        no = o;
        Light(x,y,0,-1,no);
        DFS(cctvIdx+1, no);
        break;

        case 2:
        no = o;
        Light(x,y,1,0,no);
        Light(x,y,-1,0,no);
        DFS(cctvIdx+1, no);
        no = o;
        Light(x,y,0,1,no);
        Light(x,y,0,-1,no);
        DFS(cctvIdx+1, no);
        break;

        case 3:
        no = o;
        Light(x,y,-1,0,no);
        Light(x,y,0,1,no);
        DFS(cctvIdx+1, no);
        no = o;
        Light(x,y,0,1,no);
        Light(x,y,1,0,no);
        DFS(cctvIdx+1, no);
        no = o;
        Light(x,y,1,0,no);
        Light(x,y,0,-1,no);
        DFS(cctvIdx+1, no);
        no = o;
        Light(x,y,0,-1,no);
        Light(x,y,-1,0,no);
        DFS(cctvIdx+1, no);
        break;

        case 4:
        no = o;
        Light(x,y,0,-1,no);
        Light(x,y,-1,0,no);
        Light(x,y,0,1,no);
        DFS(cctvIdx+1, no);
        no = o;
        Light(x,y,-1,0,no);
        Light(x,y,0,1,no);
        Light(x,y,1,0,no);
        DFS(cctvIdx+1, no);
        no = o;
        Light(x,y,0,1,no);
        Light(x,y,1,0,no);
        Light(x,y,0,-1,no);
        DFS(cctvIdx+1, no);
        no = o;
        Light(x,y,1,0,no);
        Light(x,y,0,-1,no);
        Light(x,y,-1,0,no);
        DFS(cctvIdx+1, no);
        break;

        case 5:
        no = o;
        Light(x,y,0,-1,no);
        Light(x,y,-1,0,no);
        Light(x,y,0,1,no);
        Light(x,y,1,0,no);
        DFS(cctvIdx+1, no);
        break;
    }
}

int main()
{
    cin >> N >> M;
    Office.resize(N+1,vector(M+1, 0));
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<M; j++)
        {
            cin >> Office[i][j];
            if(Office[i][j] > 0 && Office[i][j] != 6)
            {
                cctv.push_back({i,j});
            }
            else if(Office[i][j] == 0) answer++;
        }
    }
    DFS(0,Office);
    cout << answer;
}