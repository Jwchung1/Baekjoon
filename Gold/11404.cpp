#include <iostream>
using namespace std;

int n,m;
int A[101][101];
int main()
{
    
    cin >> n >> m;
    // A 초기화
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(i==j) A[i][j] = 0;
            else A[i][j] = INT32_MAX;
        }
    }
    // 거리 정보 입력
    for(int i=0; i<m; i++)
    {
        int a,b,c;
        cin >> a >> b >> c;
        A[a][b] = min(c,A[a][b]); // 입력된 노선이 원래 있는 노선보다 오래걸리는 애일수도 있음
    }
    // 플로이드 알고리즘
    for(int k=1; k<=n; k++)
    {
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
            {
                // k를 거쳐서 갈 수 있는지 확인
                if(A[i][k] != INT32_MAX && A[k][j] != INT32_MAX){
                    A[i][j] = min(A[i][j], A[i][k] + A[k][j]);
                }
            }
        }
    }
    // 갈 수 없는 곳 갱신
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(A[i][j] == INT32_MAX) A[i][j] = 0;
        }
    }
    // 출력
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            cout << A[i][j] << " ";
        }
        cout << "\n";
    }
}