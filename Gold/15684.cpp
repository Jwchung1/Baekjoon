// 가로선을 0개부터 3개까지 늘려가며 배치한다. (DFS 백트래킹 사용)
// 배치한 사다리에서 결과를 내보고 맞으면 결과를 출력하고 프로그램 종료, 틀리면 다음 경우의 수로 넘어가기

#include <iostream>
#include <vector>
using namespace std;

int N, M, H;
vector<vector<int>> ladder;

bool LadderResult(int ladderNum)
{
    int curLadder = ladderNum;
    for(int h=1; h<=H; h++)
    {
        curLadder = ladder[h][curLadder];
    }
    return (curLadder == ladderNum);
}

void DFS(int limit, int ladderCnt)
{
    if(ladderCnt == limit){
        for(int i=1; i<=N; i++)
        {
            if(LadderResult(i) == false) return;
        }
        cout << limit;
        exit(0);
    }
    for(int i=1; i<=H; i++)
    {
        for(int j=1; j<N; j++)
        {
            if(ladder[i][j] == j && ladder[i][j+1] == j+1)
            {
                // 사다리 없는 곳이면 놓아보기
                ladder[i][j] = j+1;
                ladder[i][j+1] = j;
                DFS(limit, ladderCnt+1);
                ladder[i][j] = j;
                ladder[i][j+1] = j+1;
            }
        }
    }
}

int main()
{
    cin >> N >> M >> H;
    ladder.resize(H+1, vector(N+1, 0));
    for(int i=1; i<=H; i++)
    {
        for(int j=1; j<=N; j++)
        {
            ladder[i][j] = j;
        }
    }
    for(int i=0;i<M; i++)
    {
        int a, b;
        cin >> a >> b;
        ladder[a][b] = b+1;
        ladder[a][b+1] = b;
    }

    for(int i=0; i<=3; i++) // i: 가로선 갯수
    {
        DFS(i, 0);
    }
    
    // 위 반복문에서 성공 안뜸.
    cout << "-1";
}