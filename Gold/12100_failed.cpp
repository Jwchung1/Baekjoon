// 해결 실패. 접근 자체는 맞았는데 보드를 상하좌우로 움직일때 범위 이탈로 segfault가 난다.

#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int N;
vector<vector<int>> board;
pair<int,int> dir[4] = {{0,1},{0,-1},{1,0},{-1,0}}; // 우, 좌, 하, 상
int max_block = 0;
void BFS()
{
    queue<pair<vector<vector<int>>, int>> q; // 보드 정보랑 몇번 움직였는지 정보
    q.push({board, 0});
    while(!q.empty())
    {
        vector<vector<int>> b = q.front().first;
        int count = q.front().second;
        q.pop();
        cout << count << ": cnt\n";
        if(count >= 6) break; // 이거 6인지 5인지 디버깅할때 최우선 고려

        for(int d=0; d<4; d++)
        {
            // 모든 블럭 해당 방향으로 이동
            vector<vector<int>> nb = b;
            if(d==0){ // 우
                for(int i=N-2; i>=0; i--){
                    for(int j=0; j<N; j++){
                        int k = i;
                        cout << "seg1\n";
                        while(true){
                            if(k+1 >= N || nb[j][k+1] != 0){
                                break;
                            }
                            nb[j][k+1] = nb[j][k];
                            nb[j][k] = 0;
                            k++;
                        }
                        cout << "seg2\n";
                        if(nb[j][k] == nb[j][k-1]){
                            nb[j][k] *= 2;
                            nb[j][k-1] = 0;
                            max_block = max(max_block, nb[j][k]);
                        }
                    }
                }
            }
            else if(d==1){ // 좌
                for(int i=1; i<N; i++){
                    for(int j=0; j<N; j++){
                        int k = i;
                        cout << "seg3\n";
                        while(true){
                            if(k-1 < 0 || nb[j][k-1] != 0){
                                break;
                            }
                            nb[j][k-1] = nb[j][k];
                            nb[j][k] = 0;
                            k--;
                        }
                        cout << "seg4\n";
                        if(nb[j][k] == nb[j][k+1]){
                            nb[j][k] *= 2;
                            nb[j][k+1] = 0;
                            max_block = max(max_block, nb[j][k]);
                        }
                    }
                }
            }
            else if(d==2){ // 하
                for(int i=N-2; i>=0; i--){
                    for(int j=0; j<N; j++){
                        int k = i;
                        cout << "seg5\n";
                        while(true){
                            if(k+1 >= N || nb[k+1][j] != 0){
                                break;
                            }
                            nb[k+1][j] = nb[k][j];
                            nb[k][j] = 0;
                            k++;
                        }
                        cout << "seg6\n";
                        if(nb[k][j] == nb[k-1][j]){
                            nb[k][j] *= 2;
                            nb[k-1][j] = 0;
                            max_block = max(max_block, nb[k][j]);
                        }
                    }
                }
            }
            else if(d==3){ // 상
                for(int i=1; i<N; i++){
                    for(int j=0; j<N; j++){
                        int k = i;
                        cout << "seg7\n";
                        while(true){
                            if(k-1 < 0 || nb[k-1][j] != 0){
                                break;
                            }
                            nb[k-1][j] = nb[k][j];
                            nb[k][j] = 0;
                            k--;
                        }
                        cout << "seg8\n";
                        if(nb[k][j] == nb[k+1][j]){
                            nb[k][j] *= 2;
                            nb[k+1][j] = 0;
                            max_block = max(max_block, nb[k][j]);
                        }
                    }
                }
            }
            q.push({nb, count+1});
        }
    }
    cout << max_block;
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
        }
    }
    BFS();
}