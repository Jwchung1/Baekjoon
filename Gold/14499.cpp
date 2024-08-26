#include <iostream>
#include <queue>
using namespace std;
int map[21][21];
queue<int> cmd;
pair<int,int> dir[5] = {{0,0},{0,1},{0,-1},{-1,0},{1,0}}; // 동서북남
int dice_value[7]; // dice[1]: 1칸에 써있는 실제 값
int cur_bottom = 6;
int cur_east = 3;
int cur_west = 4;
int cur_south = 5;
int cur_north = 2;
int cur_top = 1;

void MoveDice(int c)
{
    int tmp_bottom = cur_bottom;
    int tmp_east = cur_east;
    int tmp_west = cur_west;
    int tmp_south = cur_south;
    int tmp_north = cur_north;
    int tmp_top = cur_top;
    switch(c){ // 동서북남
        case 1:
        cur_bottom = tmp_east;
        cur_top = tmp_west;
        cur_west = tmp_bottom;
        cur_east = tmp_top;
        break;
        case 2:
        cur_bottom = tmp_west;
        cur_top = tmp_east;
        cur_west = tmp_top;
        cur_east = tmp_bottom;
        break;
        case 3:
        cur_bottom = tmp_north;
        cur_top = tmp_south;
        cur_north = tmp_top;
        cur_south = tmp_bottom;
        break;
        case 4:
        cur_bottom = tmp_south;
        cur_top = tmp_north;
        cur_north = tmp_bottom;
        cur_south = tmp_top;
        break;
    }
}

int main()
{
    int N, M, x, y, K;
    cin >> N >> M >> x >> y >> K;
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<M; j++)
        {
            cin >> map[i][j];
        }
    }
    for(int i=0; i<K; i++)
    {
        int tmp;
        cin >> tmp;
        cmd.push(tmp);
    }
    // 명령 실행
    while(!cmd.empty())
    {
        int cur_cmd = cmd.front();
        cmd.pop();
        pair<int,int> next_pos = {x + dir[cur_cmd].first, y + dir[cur_cmd].second};
        if(next_pos.first < 0 || next_pos.first >= N || next_pos.second < 0 || next_pos.second >= M)
        {
            continue;
        }
        // 여기서 다이스 움직임
        MoveDice(cur_cmd);
        x = next_pos.first;
        y = next_pos.second;

        if(map[x][y] == 0){
            // 이동한 칸이 0이면 주사위 값이 지도로
            map[x][y] = dice_value[cur_bottom];
        }
        else{
            // 이동한 칸이 0이 아니면, 지도 값이 주사위로
            dice_value[cur_bottom] = map[x][y];
            map[x][y] = 0;
        }
        cout << dice_value[cur_top] << "\n";
    }
}