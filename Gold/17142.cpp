#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> lab;
vector<vector<int>> labCpy;
int N, M;
int minTime = INT32_MAX;
int zeroNum = 0;
vector<pair<int,int>> allVirusPos;
vector<pair<int,int>> chosenVirusPos;
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

bool IsAllSpreaded()
{
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            if(labCpy[i][j] == 0) return false;
        }
    }
    return true;
}

void Simulate()
{
    int t = 0;
    int curVirusNum = 0;
    int nextVirusNum = 0;
    int curZeroNum = 0;
    queue<pair<int,int>> q; // 큐를 두개놓는 방법도 있는데, 이번엔 메모리와 코드절약을 위해 curvn이랑 nextvn으로 해보자
    labCpy = lab;
    for(auto pos: chosenVirusPos)
    {
        q.push(pos);
        labCpy[pos.first][pos.second] = 3; // 활성 바이러스는 3으로 표시. 즉, 2와 0에만 확산
        curVirusNum++;
    }

    while(!q.empty())
    {
        auto [cx, cy] = q.front();
        q.pop();
        for(int i=0; i<4; i++)
        {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if(nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
            if(labCpy[nx][ny] == 2 || labCpy[nx][ny] == 0)
            { // 2나 0이면 확산
                if(labCpy[nx][ny] == 0) curZeroNum++;
                labCpy[nx][ny] = 3;
                q.push({nx,ny});
                nextVirusNum++;
                
            }
        }

        curVirusNum--; // 이번 바이러스도 확산을 끝내고 pop된거임. 
        if(curVirusNum == 0){ // 해당 초의 바이러스가 모두 확산을 끝내고 pop됐으면, 시간이 증가하고, 다음 바이러스들 차례
            t++;
            curVirusNum = nextVirusNum;
            nextVirusNum = 0;
            if(curZeroNum == zeroNum) break;
        }
    }
    //cout << curZeroNum << "=" << zeroNum << "\n";
    // 다 뿌려졌을때만 minTime 갱신
    if(curZeroNum == zeroNum){
        minTime = min(minTime, t);
    }
}

void dfs(int t, int findStart)
{
    if(t == M)
    { // 바이러스 다 놓음. 시뮬돌리기
        Simulate();
        return;
    }
    for(int i=findStart; i<allVirusPos.size(); i++)
    {
        chosenVirusPos.push_back(allVirusPos[i]);
        dfs(t+1, i+1);
        chosenVirusPos.pop_back();
    }
}

int main()
{
    // 초기 모든 바이러스는 비활성 상태
    // 활성 상태인 바이러스는 상하좌우로 1초만에 복제
    // 활성 바이러스가 비활성 바이러스가 있는 곳으로 가면 비활성 -> 활성

    // 비활성 바이러스들 중 M개를 활성으로 바꿨을때, 모든 빈칸이 바이러스가 있게 되는 최소 시간 출력
    // M개의 바이러스를 놓는 경우의 수를 DFS로 찾고, 각 경우마다 바이러스 시뮬을 돌려서 시간을 구하자.
    
    cin >> N >> M;
    lab.resize(N+1, vector(N+1, 0));
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            cin >> lab[i][j];
            if(lab[i][j] == 2)
            {
                allVirusPos.push_back({i,j});
            }
            else if(lab[i][j] == 0) zeroNum++;
        }
    }
    if(zeroNum == 0){
        cout << 0;
        return 0;
    }
    dfs(0, 0);
    if(minTime == INT32_MAX) cout << -1;
    else cout << minTime;
}