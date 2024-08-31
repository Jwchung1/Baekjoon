// 빡구현으로 풀었는데, 더 효율적인 구현이 있다.
// 시계방향 세번 돌린거 == 반시계방향 한번 돌린거
// 처음 틀린 이유: 한면을 기준으로 돌릴때 그 면도 돌아가는걸 고려 안하고 주변 돌아가는 것만 구현함.
// RotateFace함수들 추가로 해결.

#include <iostream>
#include <string>
#include <cstring>
#include <queue>
using namespace std;

char U[3][3];
char D[3][3];
char R[3][3];
char L[3][3];
char F[3][3];
char B[3][3];

void InitCube()
{
    memset(U, 'w', sizeof(U));
    memset(D, 'y', sizeof(D));
    memset(R, 'b', sizeof(R));
    memset(L, 'g', sizeof(L));
    memset(F, 'r', sizeof(F));
    memset(B, 'o', sizeof(B));
}

void RotateFaceClockwise(char c)
{
    char tmp0;
    char tmp1;
    switch (c)
    {
    case 'U':
        tmp0 = U[0][0];
        U[0][0] = U[2][0];
        U[2][0] = U[2][2];
        U[2][2] = U[0][2];
        U[0][2] = tmp0;
        tmp1 = U[0][1];
        U[0][1] = U[1][0];
        U[1][0] = U[2][1];
        U[2][1] = U[1][2];
        U[1][2] = tmp1;
        break;
    case 'D':
        tmp0 = D[0][0];
        D[0][0] = D[2][0];
        D[2][0] = D[2][2];
        D[2][2] = D[0][2];
        D[0][2] = tmp0;
        tmp1 = D[0][1];
        D[0][1] = D[1][0];
        D[1][0] = D[2][1];
        D[2][1] = D[1][2];
        D[1][2] = tmp1;
        break;
    case 'F':
        tmp0 = F[0][0];
        F[0][0] = F[2][0];
        F[2][0] = F[2][2];
        F[2][2] = F[0][2];
        F[0][2] = tmp0;
        tmp1 = F[0][1];
        F[0][1] = F[1][0];
        F[1][0] = F[2][1];
        F[2][1] = F[1][2];
        F[1][2] = tmp1;
        break;
    case 'B':
        tmp0 = B[0][0];
        B[0][0] = B[2][0];
        B[2][0] = B[2][2];
        B[2][2] = B[0][2];
        B[0][2] = tmp0;
        tmp1 = B[0][1];
        B[0][1] = B[1][0];
        B[1][0] = B[2][1];
        B[2][1] = B[1][2];
        B[1][2] = tmp1;
        break;
    case 'L':
        tmp0 = L[0][0];
        L[0][0] = L[2][0];
        L[2][0] = L[2][2];
        L[2][2] = L[0][2];
        L[0][2] = tmp0;
        tmp1 = L[0][1];
        L[0][1] = L[1][0];
        L[1][0] = L[2][1];
        L[2][1] = L[1][2];
        L[1][2] = tmp1;
        break;
    case 'R':
        tmp0 = R[0][0];
        R[0][0] = R[2][0];
        R[2][0] = R[2][2];
        R[2][2] = R[0][2];
        R[0][2] = tmp0;
        tmp1 = R[0][1];
        R[0][1] = R[1][0];
        R[1][0] = R[2][1];
        R[2][1] = R[1][2];
        R[1][2] = tmp1;
        break;
    }
}

void RotateFaceCounterClockWise(char c)
{
    RotateFaceClockwise(c);
    RotateFaceClockwise(c);
    RotateFaceClockwise(c);
}

int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        InitCube();
        int n;
        cin >> n;
        queue<string> ops;
        for(int i=0; i<n; i++)
        {
            string op;
            cin >> op;
            ops.push(op);
        }

        while(!ops.empty())
        {
            string curOp = ops.front();
            ops.pop();
            if(curOp[1] == '+') RotateFaceClockwise(curOp[0]);
            else RotateFaceCounterClockWise(curOp[0]);

            switch (curOp[0])
            {
            case 'U':
                if(curOp[1] == '+')
                {
                    char tmp0 = F[0][0];
                    char tmp1 = F[0][1];
                    char tmp2 = F[0][2];
                    F[0][0] = R[0][0];
                    F[0][1] = R[0][1];
                    F[0][2] = R[0][2];

                    R[0][0] = B[0][0];
                    R[0][1] = B[0][1];
                    R[0][2] = B[0][2];

                    B[0][0] = L[0][0];
                    B[0][1] = L[0][1];
                    B[0][2] = L[0][2];

                    L[0][0] = tmp0;
                    L[0][1] = tmp1;
                    L[0][2] = tmp2;
                }
                else
                {
                    char tmp0 = F[0][0];
                    char tmp1 = F[0][1];
                    char tmp2 = F[0][2];
                    F[0][0] = L[0][0];
                    F[0][1] = L[0][1];
                    F[0][2] = L[0][2];

                    L[0][0] = B[0][0];
                    L[0][1] = B[0][1];
                    L[0][2] = B[0][2];

                    B[0][0] = R[0][0];
                    B[0][1] = R[0][1];
                    B[0][2] = R[0][2];

                    R[0][0] = tmp0;
                    R[0][1] = tmp1;
                    R[0][2] = tmp2;
                }
                break;
            case 'D':
                if(curOp[1] == '+')
                {
                    char tmp0 = F[2][0];
                    char tmp1 = F[2][1];
                    char tmp2 = F[2][2];
                    F[2][0] = L[2][0];
                    F[2][1] = L[2][1];
                    F[2][2] = L[2][2];

                    L[2][0] = B[2][0];
                    L[2][1] = B[2][1];
                    L[2][2] = B[2][2];

                    B[2][0] = R[2][0];
                    B[2][1] = R[2][1];
                    B[2][2] = R[2][2];

                    R[2][0] = tmp0;
                    R[2][1] = tmp1;
                    R[2][2] = tmp2;
                }
                else
                {
                    char tmp0 = F[2][0];
                    char tmp1 = F[2][1];
                    char tmp2 = F[2][2];
                    F[2][0] = R[2][0];
                    F[2][1] = R[2][1];
                    F[2][2] = R[2][2];

                    R[2][0] = B[2][0];
                    R[2][1] = B[2][1];
                    R[2][2] = B[2][2];

                    B[2][0] = L[2][0];
                    B[2][1] = L[2][1];
                    B[2][2] = L[2][2];

                    L[2][0] = tmp0;
                    L[2][1] = tmp1;
                    L[2][2] = tmp2;
                }
                break;
            case 'F':
                if(curOp[1] == '+')
                {
                    char tmp0 = U[2][0];
                    char tmp1 = U[2][1];
                    char tmp2 = U[2][2];
                    U[2][0] = L[2][2];
                    U[2][1] = L[1][2];
                    U[2][2] = L[0][2];

                    L[2][2] = D[0][2];
                    L[1][2] = D[0][1];
                    L[0][2] = D[0][0];

                    D[0][2] = R[0][0];
                    D[0][1] = R[1][0];
                    D[0][0] = R[2][0];

                    R[0][0] = tmp0;
                    R[1][0] = tmp1;
                    R[2][0] = tmp2;
                }
                else
                {
                    char tmp0 = U[2][0];
                    char tmp1 = U[2][1];
                    char tmp2 = U[2][2];
                    U[2][0] = R[0][0];
                    U[2][1] = R[1][0];
                    U[2][2] = R[2][0];

                    R[0][0] = D[0][2];
                    R[1][0] = D[0][1];
                    R[2][0] = D[0][0];

                    D[0][2] = L[2][2];
                    D[0][1] = L[1][2];
                    D[0][0] = L[0][2];

                    L[2][2] = tmp0;
                    L[1][2] = tmp1;
                    L[0][2] = tmp2;
                }
                break;
            case 'B':
                if(curOp[1] == '+')
                {
                    char tmp0 = U[0][2];
                    char tmp1 = U[0][1];
                    char tmp2 = U[0][0];
                    U[0][2] = R[2][2];
                    U[0][1] = R[1][2];
                    U[0][0] = R[0][2];

                    R[2][2] = D[2][0];
                    R[1][2] = D[2][1];
                    R[0][2] = D[2][2];

                    D[2][0] = L[0][0];
                    D[2][1] = L[1][0];
                    D[2][2] = L[2][0];

                    L[0][0] = tmp0;
                    L[1][0] = tmp1;
                    L[2][0] = tmp2;
                }
                else
                {
                    char tmp0 = U[0][2];
                    char tmp1 = U[0][1];
                    char tmp2 = U[0][0];
                    U[0][2] = L[0][0];
                    U[0][1] = L[1][0];
                    U[0][0] = L[2][0];

                    L[0][0] = D[2][0];
                    L[1][0] = D[2][1];
                    L[2][0] = D[2][2];

                    D[2][0] = R[2][2];
                    D[2][1] = R[1][2];
                    D[2][2] = R[0][2];

                    R[2][2] = tmp0;
                    R[1][2] = tmp1;
                    R[0][2] = tmp2;
                }
                break;
            case 'L':
                if(curOp[1] == '+')
                {
                    char tmp0 = U[0][0];
                    char tmp1 = U[1][0];
                    char tmp2 = U[2][0];
                    U[0][0] = B[2][2];
                    U[1][0] = B[1][2];
                    U[2][0] = B[0][2];

                    B[2][2] = D[0][0];
                    B[1][2] = D[1][0];
                    B[0][2] = D[2][0];

                    D[0][0] = F[0][0];
                    D[1][0] = F[1][0];
                    D[2][0] = F[2][0];

                    F[0][0] = tmp0;
                    F[1][0] = tmp1;
                    F[2][0] = tmp2;
                }
                else
                {
                    char tmp0 = U[0][0];
                    char tmp1 = U[1][0];
                    char tmp2 = U[2][0];
                    U[0][0] = F[0][0];
                    U[1][0] = F[1][0];
                    U[2][0] = F[2][0];

                    F[0][0] = D[0][0];
                    F[1][0] = D[1][0];
                    F[2][0] = D[2][0];

                    D[0][0] = B[2][2];
                    D[1][0] = B[1][2];
                    D[2][0] = B[0][2];

                    B[2][2] = tmp0;
                    B[1][2] = tmp1;
                    B[0][2] = tmp2;
                }
                break;
            case 'R':
                if(curOp[1] == '+')
                {
                    char tmp0 = U[0][2];
                    char tmp1 = U[1][2];
                    char tmp2 = U[2][2];
                    U[0][2] = F[0][2];
                    U[1][2] = F[1][2];
                    U[2][2] = F[2][2];

                    F[0][2] = D[0][2];
                    F[1][2] = D[1][2];
                    F[2][2] = D[2][2];

                    D[0][2] = B[2][0];
                    D[1][2] = B[1][0];
                    D[2][2] = B[0][0];

                    B[2][0] = tmp0;
                    B[1][0] = tmp1;
                    B[0][0] = tmp2;
                }
                else
                {
                    char tmp0 = U[0][2];
                    char tmp1 = U[1][2];
                    char tmp2 = U[2][2];
                    U[0][2] = B[2][0];
                    U[1][2] = B[1][0];
                    U[2][2] = B[0][0];

                    B[2][0] = D[0][2];
                    B[1][0] = D[1][2];
                    B[0][0] = D[2][2];

                    D[0][2] = F[0][2];
                    D[1][2] = F[1][2];
                    D[2][2] = F[2][2];

                    F[0][2] = tmp0;
                    F[1][2] = tmp1;
                    F[2][2] = tmp2;
                }
                break;
            }
        }
        // 윗면 출력
        for(int i=0; i<3; i++)
        {
            for(int j=0; j<3; j++)
            {
                cout << U[i][j];
            }
            cout << "\n";
        }
    }
    
}