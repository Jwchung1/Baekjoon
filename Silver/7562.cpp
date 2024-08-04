// BFS로 최단거리 찾는 문제. 그래프 있고 특정 지점까지 최단거리는 BFS로 풀면된다 기억!!!!!

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N;
pair<int,int> dir[8] = {{1,2}, {1,-2}, {-1,2}, {-1,-2}, {2,1}, {2,-1}, {-2,1}, {-2,-1}};
vector<int> results;
bool IsValid(pair<int,int> p, int I)
{
    if(p.first < 0 || p.first >= I || p.second < 0 || p.second >= I)
    {
        return false;
    }
    return true;
}

void BFS(pair<int,int> s, pair<int,int> t, int I)
{
    queue<pair<int,int>> q;
    q.push(s);
    int visited[300][300] = {0,};
    visited[s.first][s.second] = 0;
    while(!q.empty())
    {
        pair<int,int> cur = q.front();
        int dist = visited[cur.first][cur.second];
        q.pop();
        if(cur == t)
        {
            results.push_back(dist);
            break;
        }

        for(int i=0; i<8; i++)
        {
            pair<int,int> next = {cur.first + dir[i].first, cur.second + dir[i].second};
            if(IsValid(next, I) && visited[next.first][next.second] == 0 && next != s)
            {
                visited[next.first][next.second] = dist + 1;
                q.push(next);
            }
        }
    }
}

int main()
{
    cin >> N;
    while(N-- > 0)
    {
        int I;
        cin >> I;
        pair<int, int> cur, target;
        cin >> cur.first >> cur.second;
        cin >> target.first >> target.second;

        BFS(cur, target, I);
    }
    for(int i=0; i<results.size(); i++)
    {
        cout << results[i] << "\n";
    }
}