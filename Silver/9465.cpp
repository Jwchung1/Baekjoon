// DP 팁: 
// 0. 연관있는 항들까지 가지고 있는 작은 예시를 만든다. DP[i] = DP[i-1] + DP[i-2] 면 , 3개의 원소를 가지고 만든다. 
// 1. 작은 예시를 가지고 나올 수 있는 모든 경우의 수를 해본다. 
// 2. 나온 경우의 수들로 점화식을 짠다.
// 이거 세줄로 263ms -> 73ms 까지 줄여짐.
// ios::sync_with_stdio(0);
// cin.tie(0);
// cout.tie(0);

#include <iostream>
#include <vector>

using namespace std;

int T, n;
int arr[2][100000];

vector<int> result;
int main()
{
    // 이거 세줄로 263ms -> 73ms 까지 줄여짐.
    ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

    cin >> T;
    while(T > 0)
    {
        cin >> n;
        for(int i=0; i<2; i++)
        {
            for(int j=0; j<n; j++)
            {
                cin >> arr[i][j];
            }
        }
        // 풀이
        int DP[2][100000];
        DP[0][0] = arr[0][0];
        DP[1][0] = arr[1][0];
        DP[0][1] = arr[0][1] + arr[1][0];
        DP[1][1] = arr[1][1] + arr[0][0];
        for(int j=2; j<n; j++)
        {
            for(int i=0; i<2; i++)
            {
                DP[i][j] = max(DP[(i+1)%2][j-1], DP[(i+1)%2][j-2]) + arr[i][j];
            }
        }
        cout << max(DP[0][n-1], DP[1][n-1]) << "\n";
        T--;
    }
}