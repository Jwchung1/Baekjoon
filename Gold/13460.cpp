#include <iostream>
#include <queue>
using namespace std;

char board[11][11]; // 보드 정보
int N, M; // 보드 크기
pair<int,int> R_pos; // 빨간공 초기 시작 위치
pair<int,int> B_pos; // 파란공 초기 시작 위치
pair<int,int> dir[4] = {{0,1},{0,-1},{1,0},{-1,0}};
// 한 동작에 R,B 모두 멈출때까지 진행
// 한 동작 상태를 나타내는 구조체 선언
struct step{
    int Rx, Ry; // 빨간 공 위치
    int Bx, By; // 파란 공 위치
    int count;  // 움직인 횟수
};
bool visited[11][11][11][11]; // 동작 후에 파란공과 빨간공 위치가 이전에 겪었던 상황이면, pass하기 위한 배열

void BFS()
{
    queue<step> q; // 큐에는 다음 동작에 대한 정보 담음
    q.push({R_pos.first, R_pos.second, B_pos.first, B_pos.second, 0}); // 초기 상태 넣고 시작
    visited[R_pos.first][R_pos.second][B_pos.first][B_pos.second] = true;
    
    while(!q.empty())
    {
        int rx = q.front().Rx, ry = q.front().Ry;
        int bx = q.front().Bx, by = q.front().By;
        int count  = q.front().count;
        q.pop();
        if(count >= 10){ // 10번 이하로 움직여서 빨간 구슬을 빼지 못한 상황
            cout << "-1";
            return;
        }
        for(auto d: dir)
        {
            int nrx = rx, nry = ry;
            int nbx = bx, nby = by;
            int ncount = count + 1;
            int rdist = 0, bdist = 0; // 두 구슬이 겹치는 경우, 더 많이 움직인애가 더 뒤에 있었던것이므로 위치 조정
            // 두 구슬 움직이기
            while(board[nrx + d.first][nry + d.second] != '#' && board[nrx][nry] != 'O') // 다음 이동이 벽이거나, 현재 위치가 구멍이면 stop
            {
                nrx += d.first;
                nry += d.second;
                rdist++;
            }
            while(board[nbx + d.first][nby + d.second] != '#' && board[nbx][nby] != 'O') // 다음 이동이 벽이거나, 현재 위치가 구멍이면 stop
            {
                nbx += d.first;
                nby += d.second;
                bdist++;
            }

            if(board[nbx][nby] == 'O') // 파란 공이 들어간 경우 실패
            {
                // 다른 성공하는 경우 있을수도 있으니 continue
                continue;
            }
            if(board[nrx][nry] == 'O') // 파란 공이 안 들어갔고, 빨간 공이 들어갔으면 성공
            {
                cout << ncount;
                return; // 성공했으니 바로 리턴
            }
            if(nrx == nbx && nry == nby) // 둘 다 안들어갔고, 둘이 겹쳤으면 위치 조정
            {
                if(rdist > bdist){
                    // 빨간공이 더 뒤에서 출발했으니까, 한칸 뒤로 이동
                    nrx -= d.first;
                    nry -= d.second;
                }
                else{
                    // 파란공이 더 뒤에서 출발했으니까, 한칸 뒤로 이동
                    nbx -= d.first;
                    nby -= d.second;
                }
            }
            // 현 상태가 온적 있는 상태면 q에 안넣음
            if(visited[nrx][nry][nbx][nby] == true) continue;
            visited[nrx][nry][nbx][nby] = true;
            q.push({nrx,nry,nbx,nby,ncount});
        }
    }
    // 더 이상 시도할 동작이 없는데 성공을 못한 상황
    cout << "-1";
    return;
}

int main()
{
    
    cin >> N >> M;
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<M; j++)
        {
            char c;
            cin >> c;
            if(c == 'B') {
                B_pos = {i,j};
                c = '.';
            }
            if(c == 'R') {
                R_pos = {i,j};
                c = '.';
            }
            board[i][j] = c;
        }
    }
    BFS();
}