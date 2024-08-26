#include <iostream>
#include <vector>
#include <queue>
#include <deque> // 꼬리와 머리를 움직인다는 것에서 덱을 떠올려야했다.

using namespace std;
int N,K,L;
int board[102][102]; // 0이면 빈 위치, 1이면 뱀 몸통, 2면 사과
deque<pair<int,int>> snake;
queue<pair<int,char>> dir_change;
int dir_change_time;

pair<int,int> dir[4] = {{-1,0},{0,1},{1,0},{0,-1}}; // 상우하좌 시계방향
int cur_dir_idx = 1;
pair<int,int> cur_dir = dir[cur_dir_idx];

int game_time = 0;

void ChangeDir()
{
    char c = dir_change.front().second;
    dir_change.pop();
    if(dir_change.empty()) dir_change_time = -1;
    else dir_change_time = dir_change.front().first;

    if(c == 'D'){
        cur_dir_idx = (cur_dir_idx + 1)%4;
    }
    else{
        cur_dir_idx = (cur_dir_idx + 3)%4;
    }
    cur_dir = dir[cur_dir_idx];
}

void MoveTail()
{
    board[snake.back().first][snake.back().second] = 0;
    snake.pop_back();
}

void PrintBoard()
{
    cout << "time: " << game_time << "\n";
    for(int i=1; i<=N; i++)
    {
        for(int j=1; j<=N; j++)
        {
            cout << board[i][j];
        }
        cout << "\n";
    }
}

int main()
{
    
    cin >> N >> K;
    for(int i=0; i<K; i++)
    {
        int row, col;
        cin >> row >> col;
        board[row][col] = 2;
    }
    cin >> L;
    for(int i=0; i<L; i++)
    {
        int X;
        char C;
        cin >> X >> C;
        dir_change.push({X,C});
    }
    board[1][1] = 1;
    snake.push_front({1,1});
    dir_change_time = dir_change.front().first;
    while(true)
    { // 턴 시작
        game_time++;
        // 머리 이동
        pair<int,int> next_pos = {snake.front().first + cur_dir.first, snake.front().second + cur_dir.second};
        if(next_pos.first < 1 || next_pos.first > N || next_pos.second < 1 || next_pos.second > N || board[next_pos.first][next_pos.second] == 1){
            // 벽이나 몸이랑 부딪힌 경우 게임 오버   
            break;
        }
        snake.push_front(next_pos);
        if(board[next_pos.first][next_pos.second] == 2){
            // 사과를 먹은 경우
            board[next_pos.first][next_pos.second] = 1; // 사과 없어짐
        }
        else{
            // 사과를 안 먹은 경우
            board[next_pos.first][next_pos.second] = 1;
            MoveTail();
        }

        if(game_time == dir_change_time){
            ChangeDir();
        }
    }

    cout << game_time;
}