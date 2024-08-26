// visited가 없어도 되고, 없는게 더 빠르다! 어차피 지나온 길은 알파벳이 같아서 다시 안가니까 visited랑 알파벳 중복을 둘다 체크하는것은 시간과 메모리 낭비!
// direction을 pair로 하는것보다 dx, dy로 나누는게 미세하게 더 빠르다
// DFS 매개변수로 알파벳 벡터를 레퍼런스 전달하는건, 전역변수 하나 가지고 조작하는 거랑 다를게 없다.
// BFS는 최단경로 찾을 때 좋고
// DFS는 max경로 찾을 때 좋다

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int R, C;
vector<string> board;
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
vector<int> v;
int answer = 0;

void DFS(int cx, int cy, int dist) // 복사 비용을 줄이기 위한 레퍼런스 전달
{
    for(int i=0; i<4; i++)
    {
        int nx = cx + dx[i];
        int ny = cy + dy[i];
        if(nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
        int next_alph = board[nx][ny] - 'A';
        if(v[next_alph] == 1) continue;

        v[next_alph] = 1;
        DFS(nx, ny, dist + 1);
        v[next_alph] = 0;
    }
    answer = max(answer, dist);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> R >> C;
    // 지나온 알파벳을 다시 지나지 않는다. -> set 자료구조 or 비트마스킹. find에 걸리는 시간이 각각 O(logn), O(1)
    for(int i=0; i<R; i++)
    {
        string s;
        cin >> s;
        board.push_back(move(s)); // 메모리 절약을 위한 이동 시멘틱스 사용
    }

    v.resize(27,0);
    v[board[0][0] - 'A'] = 1;
    DFS(0,0,1);

    cout << answer;
}