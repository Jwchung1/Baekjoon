// max({cur_max, max_cups[i][0], max_cups[i][1]}) 3개 한번에 비교 가능..
// 점화식을 이렇게 세워도 된다.
// dp[i] = max({dp[i-3]+a[i-1]+a[i], dp[i-2]+a[i], dp[i-1]})
// 첫번째 항이 가능한 이유: i-3까지 어떻게 마셨든 최대를 더함. i-2를 건너뛰기 때문에 상관이 없고, 그 후에 i-1, i를 연속으로 마심
// 두번째 항이 가능한 이유: i-2까지 어떻게 마셨든 최대를 더함. i-1을 건너뛰기 때문에 상관이 없고, i를 마심
// 세번째 항이 가능한 이유: i-1까지 어떻게 마셨든 최대를 더함. 현재꺼는 안마심. 연속될수도 있어서 마시면 안됨.

#include <iostream>
#include <algorithm>

using namespace std;

int n;
int cups[10000];
int max_cups[10001][3]; // 0: 전꺼 마시고 또 마심, 1: 전꺼 안마시고 마심, 2: 전전꺼까지의 최댓값

int main()
{
    cin >> n;
    for(int i=0; i<n; i++)
    {
        cin >> cups[i];
    }

    max_cups[0][0] = cups[0];
    max_cups[0][1] = cups[0];
    max_cups[0][2] = cups[0];

    max_cups[1][0] = cups[1] + cups[0];
    max_cups[1][1] = cups[1];
    max_cups[1][2] = cups[1] + cups[0];

    int cur_max = max_cups[1][2];

    for(int i=2; i<n; i++)
    {
        max_cups[i][0] = max_cups[i-1][1] + cups[i];
        max_cups[i][1] = max_cups[i-2][2] + cups[i];
        cur_max = max({cur_max, max_cups[i][0], max_cups[i][1]});
        max_cups[i][2] = cur_max;
    }

    int max = 0;
    for(int i=0; i<n+1; i++)
    {
        for(int j=0; j<3; j++)
        {
            if(max_cups[i][j] > max) max = max_cups[i][j];
        }
    }
    cout << max;
}