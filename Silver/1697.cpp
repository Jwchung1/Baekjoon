// 메모리초과가 뜬 BFS 문제. BFS는 방문한곳을 또 했을때 그게 최단거리가 될 가능성이 없기 때문에, 방문하지 않은 곳만 가주면 된다. -> visited[] 배열 추가
// 목표지점을 넘어가는 순간, x+1과 x*2는 할 이유가 없다. 불필요한 q.push를 줄여주기 위해 조건 추가
// visited 배열은 현 구현에서 99999*2 = 199,998 까지 갈수 있다. -> visited 배열 크기 200001로 선언

#include <iostream>
#include <queue>

using namespace std;

int N, K;
int visited[200001];
int main()
{
    cin >> N >> K;

    queue<pair<int,int>> q; 
    q.push(make_pair(N,0));
    int result;
    while(!q.empty())
    {
        pair<int,int> cur_pos = q.front();
        visited[cur_pos.first] = 1;
        q.pop();
        if(cur_pos.first == K)
        {
            result = cur_pos.second;
            break;
        }

        if(cur_pos.first + 1 >= 0 && cur_pos.first < K && visited[cur_pos.first + 1] != 1) q.push(make_pair(cur_pos.first + 1, cur_pos.second + 1));
        if(cur_pos.first - 1 >= 0 && visited[cur_pos.first - 1] != 1) q.push(make_pair(cur_pos.first - 1, cur_pos.second + 1));
        if(cur_pos.first < K && visited[cur_pos.first * 2] != 1) q.push(make_pair(cur_pos.first * 2, cur_pos.second + 1));
    }
    cout << result;
}