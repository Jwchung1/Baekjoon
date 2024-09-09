// key idea: DP를 0,0에서 좌하단 방향으로 채워나가면 구불구불한 길을 표현할 수 없다.
// 이미 DP가 계산됐는데 다음칸이 이전칸보다 높이가 높다면 이전칸을 다시 갱신해야하는데 그러지 못하기 때문.
// 따라서, 높이가 높은 칸부터 DP를 계산해 나가면 모든 경우가 포함된다. 
// 이때, DP의 초기화는 시작하는 칸만 1로 두어야 의미 상 올바르다. 시작하는 칸은 언제나 갈 수 있고, 나머지칸들은 미지이기 떄문에 0으로 둔다. 
// 이건 DP 풀이고, DFS풀이도 가능하다.
// DFS 풀이: 끝에 도달하면 return 1
// 계속 더해나간다.

// DP풀이----------------------------------------------------
// #include <iostream>
// #include <map> // map으로 정렬하고 도는건 중복이 존재해서 안됨
// #include <queue> // 우선순위큐로 정렬하고 돌자
// using namespace std;
// int M, N;
// int Map[502][502];
// int DP[502][502];
// int dx[4] = {0,0,-1,1};
// int dy[4] = {1,-1,0,0};
// priority_queue<pair<int,pair<int,int>>> pq;
// int main()
// {
//     cin >> M >> N;
//     for(int i=0; i<M; i++)
//     {
//         for(int j=0; j<N; j++)
//         {
//             cin >> Map[i][j];
//             pq.push({Map[i][j], {i,j}});
//         }
//     }
//     DP[0][0] = 1;
    
//     while(!pq.empty())
//     { // 내림차순으로 큰거부터 순회
//         int px = pq.top().second.first;
//         int py = pq.top().second.second;
//         int h = pq.top().first;
//         pq.pop();
//         for(int i=0; i<4; i++)
//         {
//             int nx = px + dx[i];
//             int ny = py + dy[i];
//             if(nx < 0 || nx >= M || ny < 0 || ny >= N) continue;
//             if(Map[nx][ny] > Map[px][py])
//             {
//                 DP[px][py] += DP[nx][ny];
//             }
//         }
//     }
//     cout << DP[M-1][N-1];
// }

// DFS 풀이-------------------------------------------
// -1로 초기화 하고 방문했을때 0으로 바꿔주는 이유가 뭘까? 처음부터 0으로 초기화하면 안되나?
// 아예 못 가는 곳과 갈 수 있는데 끝점에 도달하지 않는 곳을 구분하기 위해서이다. 
#include <iostream>
#include <cstring>
using namespace std;
int Map[502][502];
int DP[502][502];
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
int M,N;
int answer = 0;
// DFS로 시작점에서 끝점까지 길 찾기.
// 끝점 도달시 정답+1,
int DFS(int x, int y)
{
    // for(int i=0; i<M; i++)
    // {
    //     for(int j=0; j<N; j++)
    //     {
    //         cout << DP[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    if(x==M-1 && y==N-1)
    {
        return 1;
    }
    if(x < 0 || x >= M || y < 0 || y >= N)
    {
        // 범위 밖이면 0 반환
        return 0;
    }
    if(DP[x][y] != -1)
    {
        return DP[x][y]; // 왔던곳이면 더 갈 필요없이 그 위치에서 끝점까지의 경우의 수가 담긴 DP를 반환하면됨.
    }

    DP[x][y] = 0;
    for(int i=0; i<4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        if(Map[x][y] > Map[nx][ny])
        {
            DP[x][y] += DFS(nx,ny);
        }
    }
    // 그 점에서 더 이상 갈 곳이 없으면 저장된 DP를 반환
    return DP[x][y];
}

int main()
{
    cin >> M >> N;
    memset(DP, -1, sizeof(DP));
    for(int i=0; i<M; i++)
    {
        for(int j=0; j<N; j++)
        {
            cin >> Map[i][j];
        }
    }
    
    cout << DFS(0,0);
}