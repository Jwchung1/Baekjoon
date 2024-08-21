#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int N;
int water[21][21];

struct comp{
    bool operator()(pair<int,int> p1, pair<int,int> p2){
        if(p1.first != p2.first) return p1.first > p2.first;
        else{
            return p1.second > p2.second;
        } 
    }
};

vector<priority_queue<pair<int,int>, vector<pair<int,int>>, comp>> fishes; // fishes[i]는 i 크기 이하의 물고기들 담은 우선순위 큐
pair<int,int> shark_pos;
int shark_size = 2;
int ate_num = 0;
int total_time = 0;
pair<int,int> dir[4] = {{0,1},{0,-1},{-1,0},{1,0}};

bool IsValid(pair<int,int> p)
{
    if(p.first < 0 || p.first >= N || p.second < 0 || p.second >= N || water[p.first][p.second] > shark_size) return false;
    return true;
}

bool MoveTo(pair<int,int> dest) // 먹는거 성공하면 true, 아니면 false
{
    int visited[21][21] = {0,};
    queue<pair<int,int>> q;
    q.push(shark_pos);
    visited[shark_pos.first][shark_pos.second] = 1;
    bool eat_success = false;
    while(!q.empty())
    {
        pair<int,int> cur = q.front();
        q.pop();
        if(cur == dest){
            water[cur.first][cur.second] = 0;
            eat_success = true;
            break;
        }
        for(auto d : dir)
        {
            pair<int,int> next = {cur.first + d.first, cur.second + d.second};
            if(IsValid(next) && visited[next.first][next.second] == 0)
            {
                visited[next.first][next.second] = visited[cur.first][cur.second] + 1;
                q.push(next);
            }
        }
    }
    if(eat_success){
        // 먹었을때 변수들 갱신
        total_time += visited[dest.first][dest.second] - 1;
        ate_num++;
        if(ate_num == shark_size){
            // 상어 진화
            shark_size++;
            ate_num = 0;
            // 먹을 수 있는 큐 갱신
            while(!fishes[shark_size-1].empty()){
                cout << "push pop\n";
                fishes[shark_size].push(fishes[shark_size-1].top());
                fishes[shark_size-1].pop();
            }
        }
    } 
    return eat_success;
}

int main()
{
    // 크기 같으면 지나가기 가능
    // 크기 작은건 먹으면서 지나가기
    // 크기 큰건 못 지나감
    // 1초에 한칸씩 이동가능
    cin >> N;
    fishes.resize(7);
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            int a;
            cin >> a;
            water[i][j] = a;
            if(a == 9) {
                shark_pos = {i,j};
                water[i][j] = 0;
            }
            else if(a >=1) fishes[a].push({i,j});
        }
    }
    // while(!fishes[1].empty()){
    //     cout << fishes[1].top().first << ", " << fishes[1].top().second << "\n";
    //     fishes[1].pop();
    // }
    // 먹을수 있는것중에서 가장 가까운 타겟을 정해. 그럼 가는 길에 먹는건 불가능
    while(true)
    {
        cout << "shark size: " << shark_size << "\n";
        cout << fishes[shark_size-1].top().first << ", " << fishes[shark_size-1].top().second << "\n";
        bool eatable_fish_exist = false;
        pair<int,int> target_fish;
        if(fishes[shark_size-1].empty() == 0){
            target_fish = fishes[shark_size-1].top();
            fishes[shark_size-1].pop();
            eatable_fish_exist = true;
        }
        if(eatable_fish_exist == false) break; // 먹을수있는게 없으면 멈춤
        else{
            cout << "target_fish: " << target_fish.first << "," << target_fish.second << "\n";
            bool move_success = MoveTo(target_fish);
            if(move_success) shark_pos = target_fish; // 이동 성공했으면 상어 위치 변경
        }
    }

    cout << total_time;
}