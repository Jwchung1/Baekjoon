// set는 연산이 복잡하고 오래걸리니까, 비트마스킹으로 가능한 숫자 찾아서 넣자. (시간초과 해결)

#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> board;
vector<pair<int,int>> empties;

void FindAbleNums(const pair<int,int>& p, vector<int>& ableNums)
{
    // 정사각형에 있는 숫자들 빼기
    int xStart = (p.first/3)*3;
    int yStart = (p.second/3)*3;
    for(int i=xStart; i<xStart + 3; i++)
    {
        for(int j=yStart; j<yStart + 3; j++)
        {
            ableNums[board[i][j]] = 1;
        }
    }
    // 가로세로에 있는 숫자들 빼기
    for(int i=0; i<9; i++)
    {
        ableNums[board[p.first][i]] = 1;
        ableNums[board[i][p.second]] = 1;
    }
}

void DFS(int filledEmpties)
{
    if(filledEmpties >= empties.size())
    {
        for(int i=0; i<9; i++)
        {
            for(int j=0; j<9; j++)
            {
                cout << board[i][j] << " ";
            }
            cout << "\n";
        }
        exit(0);
    }

    pair<int,int> emptyToFill = empties[filledEmpties];
    vector<int> ableNums;
    ableNums.resize(10,0);
    FindAbleNums(emptyToFill, ableNums);
    for(int i=1; i<=9; i++)
    {
        if(ableNums[i] == 0)
        {
            board[emptyToFill.first][emptyToFill.second] = i;
            DFS(filledEmpties + 1);
            board[emptyToFill.first][emptyToFill.second] = 0;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    board.resize(10,vector(10,0));
    for(int i=0; i<9; i++)
    {
        for(int j=0; j<9; j++)
        {
            cin >> board[i][j];
            if(board[i][j] == 0) empties.push_back({i,j});
        }
    }

    DFS(0);
}