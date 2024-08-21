// 상어위치에서 BFS진행. dir순서는 상 좌 우 하.
// 상어크기보다 크면 막힘.
// 상어크기와 같으면 진행.
// 상어크기보다 작으면 먹고(water = 0으로 만들고) break후, 다시 BFS진행
// BFS 끝났는데, 아무것도 못 먹었으면 BFS 종료

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int N;
int water[21][21];
pair<int,int> shark_pos;
int shark_size = 2;
int ate_num = 0;
int total_time = 0;
pair<int,int> dir[4] = {{-1,0},{0,-1},{0,1},{1,0}}; // 상 좌 우 하  높은거 먼저니까 하가 가장 마지막

struct comp{
    bool operator()(pair<int,int> p1, pair<int,int> p2){
        if(p1.first != p2.first) return p1.first > p2.first;
        else{
            return p1.second > p2.second;
        } 
    }
};

priority_queue<pair<int,int>, vector<pair<int,int>>, comp> fishes; // fishes에 먹을수있는 물고기들 담음

bool IsValid(pair<int,int> p)
{
    if(p.first < 0 || p.first >= N || p.second < 0 || p.second >= N || water[p.first][p.second] > shark_size) return false;
    return true;
}

void BFS(pair<int,int> start) // 먹는거 성공하면 BFS다시, 아니면 return
{
    int visited[21][21] = {0,};
    queue<pair<int,int>> q;
    q.push(start);
    visited[start.first][start.second] = 1;
    bool eat_success = false;
    int shortest_time = -1;
    while(!q.empty())
    {
        pair<int,int> cur = q.front();
        q.pop();
        if(water[cur.first][cur.second] < shark_size && water[cur.first][cur.second] > 0){
            if(shortest_time == -1) {
                shortest_time = visited[cur.first][cur.second];
                fishes.push(cur);
                eat_success = true;
            }
            else{
                if(shortest_time == visited[cur.first][cur.second]){
                    fishes.push(cur);
                    eat_success = true;
                }
            }
            
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
    if(eat_success == true) {
        pair<int,int> prey = fishes.top();
        while(!fishes.empty()) fishes.pop(); 
        total_time += visited[prey.first][prey.second] - 1;
        shark_pos = prey;
        water[prey.first][prey.second] = 0;
        ate_num++;
        if(ate_num == shark_size){
            shark_size++;
            ate_num = 0;
        }
        BFS(shark_pos);
    }
    else return;
}

int main()
{
    cin >> N;
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
        }
    }
    BFS(shark_pos);
    cout << total_time;
}