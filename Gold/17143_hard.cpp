#include <iostream>
#include <map>
using namespace std;
int R, C, M;
int dx[5] = {0,-1,1,0,0};
int dy[5] = {0,0,0,1,-1}; // 1위 2아래 3오른쪽 4왼쪽
struct shark{
    int s;
    int d;
    int z;
    bool alive;
    shark() : s(0), d(0), z(0), alive(false) {}
    shark(int inS, int inD, int inZ)
    {
        s = inS;
        d = inD;
        z = inZ;
    }
};

shark grid[101][101]; // z가 0이면 그 칸엔 없는거
shark grid_tmp[101][101];
map<int, tuple<int,int,bool>> sharks;

int inverseDir(int d)
{
    if(d==1) return 2;
    else if(d==2) return 1;
    else if(d==3) return 4;
    else if(d==4) return 3;
    return 0;
}

void initGrid()
{
    for(int i=1; i<=R; i++)
    {
        for(int j=1; j<=C; j++)
        {
            grid_tmp[i][j].z = 0;
        }
    }
}

void copyGrid()
{
    for(int i=1; i<=R; i++)
    {
        for(int j=1; j<=C; j++)
        {
            grid[i][j].z = grid_tmp[i][j].z;
        }
    }
}

void debug()
{
    for(int i=1; i<=R; i++)
    {
        for(int j=1; j<=C; j++)
        {
            cout << grid[i][j].z << " ";
        }
        cout << "\n";
    }
}

int main()
{
    cin >> R >> C >> M;
    for(int i=0; i<M; i++)
    {
        int r, c, s, d, z;
        cin >> r >> c >> s >> d >> z;
        grid[r][c].s = s;
        grid[r][c].d = d;
        grid[r][c].z = z;
        sharks[z] = {r,c,true};
    }
    int fisher = 0;
    int answer = 0;
    while(true)
    {
        fisher++; // 낚시왕이 한칸 이동
        if(fisher > C) break;
        // cout << "fisher loc: " << fisher << "\n";
        // debug();
        // 땅과 제일 가까운 상어 잡기
        for(int i=1; i<=R; i++)
        {
            if(grid[i][fisher].z > 0){
                answer += grid[i][fisher].z;
                sharks.erase(grid[i][fisher].z);
                grid[i][fisher].z = 0;
                break;
            }
        }
        // 상어 이동 (map에 저장된 상어들을 움직임)
        initGrid();
        for(auto it=sharks.begin(); it != sharks.end(); it++)
        {
            auto [cr, cc, isAlive] = it->second;
            if(isAlive == false) continue;
            int dir = grid[cr][cc].d;
            int speed = grid[cr][cc].s;
            int size = grid[cr][cc].z;

            int nr = cr + dx[dir]*speed;
            int nc = cc + dy[dir]*speed;
            int residue;
            while(true)
            {
                if(nr < 1)
                {// 격자 밖에 나갔으면 나간만큼의 두배만큼 역방향으로 이동
                    residue = abs(1 - nr) * 2;
                    nr = nr + residue;
                    dir = inverseDir(dir);
                }
                else if(nr > R)
                {
                    residue = abs(R - nr) * 2;
                    nr = nr - residue;
                    dir = inverseDir(dir);
                }
                else if(nc < 1)
                {
                    residue = abs(1 - nc) * 2;
                    nc = nc + residue;
                    dir = inverseDir(dir);
                }
                else if(nc > C)
                {
                    residue = abs(C - nc) * 2;
                    nc = nc - residue;
                    dir = inverseDir(dir);
                }
                else break;
            }
            // 원래 있던 칸 지우기
           // grid[cr][cc].z = 0;
            // 새로운 칸의 상어가 크기가 더 작은 경우 입장 (0 예외처리?)
            if(grid_tmp[nr][nc].z < size)
            {
                // 이미 있던 생선 삭제
                sharks[grid_tmp[nr][nc].z] = {nr,nc,false};
                // 입장
                grid_tmp[nr][nc].z = size;
                grid_tmp[nr][nc].s = speed;
                grid_tmp[nr][nc].d = dir;
                sharks[size] = {nr,nc,true};
            }
            else{
                // 아닌 경우 현재 상어 삭제
                sharks[size] = {nr,nc,false};
            }
        }
        copyGrid();
    }
    cout << answer;
}