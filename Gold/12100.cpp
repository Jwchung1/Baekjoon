// 한쪽으로 깊이 들어가는 완전탐색 문제는 DFS다. DFS로 해야 해당 경우의 인과 파악이 돼서 디버깅이 쉽다. 최단거리는 BFS!
// BFS 솔루션: 메모리 4404KB, 시간 12ms
// DFS 솔루션: 메모리 2024KB, 시간 12ms
// 보드를 상하좌우로 움직이는 시뮬레이션을 정확히 구현하는게 관건이었던 문제.

#include <iostream>
#include <vector>
using namespace std;
int N;
vector<vector<int>> board;
pair<int,int> dir[4] = {{0,1},{0,-1},{1,0},{-1,0}}; // 우, 좌, 하, 상
int max_block = 0;

void DFS(int moveCount, vector<vector<int>> b)
{
    if(moveCount == 5)
    {
        return;
    }
    for(int d=0; d<4; d++)
    {
        // 모든 블럭 해당 방향으로 이동
        vector<vector<int>> nb = b;
        int isMerged[21][21] = {0,};
        if(d==0){ // 우
            for(int i=N-2; i>=0; i--){
                for(int j=0; j<N; j++){
                    int k = i;
                    while(true){
                        if(k+1 >= N || nb[j][k+1] != 0){
                            break;
                        }
                        nb[j][k+1] = nb[j][k];
                        nb[j][k] = 0;
                        k++;
                    }
                    if(k+1 != N && nb[j][k] == nb[j][k+1] && isMerged[j][k+1] == 0){
                        isMerged[j][k+1] = 1;
                        nb[j][k+1] *= 2;
                        nb[j][k] = 0;
                        max_block = max(max_block, nb[j][k+1]);
                    }
                }
            }
        }
        else if(d==1){ // 좌
            for(int i=1; i<N; i++){
                for(int j=0; j<N; j++){
                    int k = i;
                    while(true){
                        if(k-1 < 0 || nb[j][k-1] != 0){
                            break;
                        }
                        nb[j][k-1] = nb[j][k];
                        nb[j][k] = 0;
                        k--;
                    }
                    if(k != 0 && nb[j][k] == nb[j][k-1] && isMerged[j][k-1] == 0){
                        isMerged[j][k-1] = 1;
                        nb[j][k-1] *= 2;
                        nb[j][k] = 0;
                        max_block = max(max_block, nb[j][k-1]);
                    }
                }
            }
        }
        else if(d==2){ // 하
            for(int i=N-2; i>=0; i--){
                for(int j=0; j<N; j++){
                    int k = i;
                    while(true){
                        if(k+1 >= N || nb[k+1][j] != 0){
                            break;
                        }
                        nb[k+1][j] = nb[k][j];
                        nb[k][j] = 0;
                        k++;
                    }
                    if(k+1 != N && nb[k][j] == nb[k+1][j] && isMerged[k+1][j] == 0){
                        isMerged[k+1][j] = 1;
                        nb[k+1][j] *= 2;
                        nb[k][j] = 0;
                        max_block = max(max_block, nb[k+1][j]);
                    }
                }
            }
        }
        else if(d==3){ // 상
            for(int i=1; i<N; i++){
                for(int j=0; j<N; j++){
                    int k = i;
                    while(true){
                        if(k-1 < 0 || nb[k-1][j] != 0){
                            break;
                        }
                        nb[k-1][j] = nb[k][j];
                        nb[k][j] = 0;
                        k--;
                    }
                    if(k != 0 && nb[k][j] == nb[k-1][j] && isMerged[k-1][j] == 0){
                        isMerged[k-1][j] = 1;
                        nb[k-1][j] *= 2;
                        nb[k][j] = 0;
                        max_block = max(max_block, nb[k-1][j]);
                    }
                }
            }
        }
        DFS(moveCount+1, nb);
    }
}

int main()
{
    cin >> N;
    board.resize(N, vector<int>(N,0));
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            cin >> board[i][j];
            max_block = max(max_block, board[i][j]);
        }
    }
    DFS(0, board);
    cout << max_block;
}