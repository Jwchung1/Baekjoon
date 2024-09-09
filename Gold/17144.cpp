#include <iostream>
using namespace std;

int room[51][51];
int tmp[51][51];
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
int R, C, T;
int airconTop, airconBot;

void spread(int x, int y)
{
    int spreadAmount = room[x][y]/5;
    for(int i=0; i<4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
        if(room[nx][ny] >= 0){
            // 확산
            tmp[nx][ny] += spreadAmount;
            room[x][y] -= spreadAmount;
        }
    }
}

void debug()
{

    for(int i=0; i<R; i++)
    {
        for(int j=0; j<C; j++)
        {
            cout << room[i][j] << " ";
        }
        cout << "\n";
    }
}

int main()
{   
    cin >> R >> C >> T;
    for(int i=0; i<R; i++)
    {
        for(int j=0; j<C; j++)
        {
            cin >> room[i][j];
        }
    }
    for(int i=0; i<R; i++)
    {
        if(room[i][0] == -1){
            airconTop = i;
            airconBot = i+1;
            break;
        }
    }

    while(T--)
    {
        for(int i=0; i<R; i++)
        {
            for(int j=0; j<C; j++)
            {
                if(room[i][j] > 0) spread(i,j);
            }
        }

        for(int i=0; i<R; i++)
        {
            for(int j=0; j<C; j++)
            {
                room[i][j] += tmp[i][j];
                tmp[i][j] = 0;
            }
        }
        // 위쪽 바람 돌리기
        for(int i = airconTop-1; i>=0; i--)
        {
            if(i == airconTop-1) room[i][0] = 0;
            else{
                room[i+1][0] = room[i][0];
            }
        }
        for(int i=1; i<C; i++)
        {
            room[0][i-1] = room[0][i];
        }
        for(int i=1; i<=airconTop; i++)
        {
            room[i-1][C-1] = room[i][C-1];
        }
        for(int i=C-2; i>=1; i--)
        {
            room[airconTop][i+1] = room[airconTop][i];
            if(i==1) room[airconTop][i] = 0;
        }

        // 아래쪽 바람 돌리기
        for(int i=airconBot+1; i<R; i++)
        {
            if(i == airconBot+1) room[i][0] = 0;
            else{
                room[i-1][0] = room[i][0];
            }
        }
        for(int i=1; i<C; i++)
        {
            room[R-1][i-1] = room[R-1][i];
        }
        for(int i=R-2; i>= airconBot; i--)
        {
            room[i+1][C-1] = room[i][C-1];
        }
        for(int i=C-2; i>=1; i--)
        {
            room[airconBot][i+1] = room[airconBot][i];
            if(i==1) room[airconBot][i] = 0;
        }
    }
    int sum = 0;
    for(int i=0; i<R; i++)
    {
        for(int j=0; j<C; j++)
        {
            sum += room[i][j];
        }
    }
    cout << sum+2;
}