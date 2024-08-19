#include <iostream>
#include <queue>
#include <vector>
using namespace std;
pair<int,int> dir[4] = {{0,1},{0,-1},{1,0},{-1,0}};
vector<int> results;
bool IsValid(pair<int,int> p, int m, int n)
{
    if(p.first < 0 || p.first >= m || p.second < 0 || p.second >= n) return false;
    return true;
}

int main()
{
    int T;
    cin >> T;
    while(T-- > 0)
    {
        int M, N, K;
        int answer = 0;
        cin >> M >> N >> K;
        int bat[51][51] = {0,};
        while(K-- > 0)
        {
            int X, Y;
            cin >> X >> Y;
            bat[X][Y] = 1;
        }
        for(int i=0; i<M; i++)
        {
            for(int j=0; j<N; j++)
            {
                if(bat[i][j] == 1)
                {
                    answer++;
                    queue<pair<int,int>> q;
                    q.push({i,j});
                    while(!q.empty())
                    {
                        pair<int,int> cur = q.front();
                        q.pop();
                        for(auto d : dir)
                        {
                            pair<int,int> next = {cur.first + d.first, cur.second + d.second};
                            if(IsValid(next, M, N) && bat[next.first][next.second] == 1)
                            {
                                bat[next.first][next.second] = 0;
                                q.push(next);
                            }
                        }
                    }
                }
            }
        }
        results.push_back(answer);
    }
    for(auto r: results)
    {
        cout << r << "\n";
    }
}