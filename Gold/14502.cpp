#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<vector<int>> Lab;
vector<vector<int>> Lab_copy;
vector<pair<int,int>> zeros;
vector<pair<int,int>> viruses;
vector<vector<pair<int,int>>> wall_combs;
pair<int,int> dir[4] = {{0,1},{0,-1},{1,0},{-1,0}};
int N,M;

void MakeComb(vector<pair<int,int>>& v, int find_start)
{
    if(v.size() == 3)
    {
        wall_combs.push_back(v);
        return;
    }
    for(int i=find_start; i<zeros.size(); i++)
    {
        v.push_back(zeros[i]);
        MakeComb(v, i+1);
        v.pop_back();
    }
}

void Spread(pair<int,int> s)
{
    queue<pair<int,int>> q;
    int visited[9][9] = {0,};
    visited[s.first][s.second] = 1;
    q.push(s);
    while(!q.empty())
    {
        pair<int,int> cur = q.front();
        q.pop();
        for(auto d:dir)
        {
            pair<int,int> next = {cur.first + d.first, cur.second + d.second};
            if(next.first < 0 || next.first >= N || next.second < 0 || next.second >= M) continue;
            if(visited[next.first][next.second] == 1) continue;
            if(Lab_copy[next.first][next.second] == 0)
            {
                Lab_copy[next.first][next.second] = 2;
                visited[next.first][next.second] = 1;
                q.push(next);
            }
        }
    }
}

int main()
{
    
    cin >> N >> M;
    Lab.resize(N+1, vector(M+1,0));
    // 벽을 3개 세우는 모든 경우의수를 돌려본다?
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<M; j++)
        {
            cin >> Lab[i][j];
            if(Lab[i][j] == 0)
            {
                zeros.push_back({i,j}); // rvalue 이동 시멘틱스로 메모리 낭비없음
            }
            else if(Lab[i][j] == 2)
            {
                viruses.push_back({i,j});
            }
        }
    }
    vector<pair<int,int>> tmp;
    MakeComb(tmp, 0);
    int answer = 0;
    for(auto walls : wall_combs)
    {
        Lab_copy = Lab;
        Lab_copy[walls[0].first][walls[0].second] = 1;
        Lab_copy[walls[1].first][walls[1].second] = 1;
        Lab_copy[walls[2].first][walls[2].second] = 1;
        for(auto virus : viruses)
        {
            Spread(virus);
        }
        int safe = 0;
        for(int i=0; i<N; i++)
        {
            for(int j=0; j<M; j++)
            {
                if(Lab_copy[i][j] == 0) safe++;
            }
        }
        answer = max(answer, safe);
    }
    cout << answer;
}