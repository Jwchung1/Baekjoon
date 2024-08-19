#include <iostream>
#include <vector>
using namespace std;
int N, M;
int DP[100001]; // DP[i] = i번쨰 수 까지의 합
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;
    DP[0] = 0;
    for(int i=1; i<=N; i++)
    {
        int tmp;
        cin >> tmp;
        DP[i] = DP[i-1] + tmp;
    }
    for(int i=0; i<M; i++)
    {
        int start, end;
        cin >> start >> end;
        cout << DP[end] - DP[start-1] << "\n";
    }
}