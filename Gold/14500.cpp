// DFS로 탐색 가능한 테트로미노와 불가능한 테트로미노 때문에 어떻게 할지 곤란했던 문제.
// 단순하게 불가능한 테트로미노만 따로 계산해서 고려해주면 됐다.

#include <iostream>
#include <queue>
#include <tuple>
using namespace std;
int N, M;
int paper[502][502];
int visited[502][502];
pair<int,int> dir[4] = {{0,1},{0,-1},{1,0},{-1,0}};
int answer = 0;

void DFS(int sx, int sy, int cnt, int val)
{
    if(cnt == 4){
        answer = max(answer, val);
        return;
    }
    for(auto d: dir)
    {
        int nx = sx + d.first;
        int ny = sy + d.second;
        if(nx < 1 || nx > N || ny < 1 || ny > M) continue;
        if(visited[nx][ny] == 1) continue;
        visited[nx][ny] = 1;
        DFS(nx, ny, cnt + 1, val + paper[nx][ny]);
        visited[nx][ny] = 0;
    }
}

int main()
{
    // 입력
    cin >> N >> M;
    for(int i=1; i<=N; i++)
    {
        for(int j=1; j<=M; j++)
        {
            cin >> paper[i][j];
        }
    }
    // 솔루션
    for(int i=1; i<=N; i++)
    {
        for(int j=1; j<=M; j++)
        {
            visited[i][j] = 1;
            DFS(i,j, 1, paper[i][j]);
            visited[i][j] = 0;
            // 보라색 테트로미노 체크
            int min_adj = min(min(paper[i-1][j], paper[i+1][j]), min(paper[i][j+1], paper[i][j-1]));
            int purple_tet = paper[i-1][j] + paper[i+1][j] + paper[i][j+1] + paper[i][j-1] + paper[i][j] - min_adj;
            answer = max(answer, purple_tet);
        }
    }
    cout << answer;
}