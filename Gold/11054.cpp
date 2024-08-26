// 오른쪽 방향 DP 한번, 왼쪽방향 DP 한번. 바이토닉 수열은 DP 두번해야한다!
// DP 계산할때 꼭 선형적이어야 한다는 편견 버리자. 처음부터 다시 돌아도 되는 문제도 존재한다.

#include <iostream>
#include <vector>
using namespace std;
int DP_inc[1002];
int DP_dec[1002];
int answer = 0;
int main()
{
    int N;
    vector<int> A;
    cin >> N;
    A.resize(N+1);
    for(int i=0; i<N; i++)
    {
        cin >> A[i]; 
    }
    fill(DP_inc, DP_inc + 1002, 1);
    fill(DP_dec, DP_dec + 1002, 1);
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<i; j++)
        {
            if(A[j] < A[i])
            {
                DP_inc[i] = max(DP_inc[i], DP_inc[j] + 1);
            }
        }
    }
    for(int i=N-1; i>=0; i--)
    {
        for(int j=N-1; j>i; j--)
        {
            if(A[j] < A[i])
            {
                DP_dec[i] = max(DP_dec[i], DP_dec[j] + 1);
            }
        }
    }
    for(int i=0; i<N; i++)
    {
        answer = max(answer, DP_inc[i] + DP_dec[i]);
    }
    cout << answer-1;
}