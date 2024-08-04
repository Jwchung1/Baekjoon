// DP 자체는 단순하지만, 결과를 계산할때 생각을 요했던 문제.
// 결과를 계산할 때의 복잡함을 DP에 포함해서 하려다가 꼬였다. 두 파트로 나눠서 생각하는 것도 연습하자.
// DP에는 (1,1)에서 (i,j) 까지의 합을 단순하게 구해준다.
// 나중에 결과를 구할 때, (x1,y1)에서 (x2,y2)의 합을 구할때 포함하는 영역을 생각해서 빼고 중복되는건 한번 더해주고 하는 식으로 하면된다.

#include <iostream>
#include <vector>

using namespace std;

int N, M;
int arr[1025][1025];
int DP[1025][1025]; // DP[i][j] 에는 (1,1)에서 (i,j) 까지의 합을 담는다
// 정답은 (x1, y1) (x2,y2)일때, DP(x2,y2) - DP(x2, y1-1) - DP(x1-1, y2) + DP(x1-1, y1-1)
vector<int> results;
int main()
{
    cin >> N >> M;
    for(int i=1; i<=N; i++)
    {
        for(int j=1; j<=N; j++)
        {
            cin >> arr[i][j];
        }
    }
    // DP 채우기
    for(int i=1; i<=N; i++)
    {
        for(int j=1; j<=N; j++)
        {
            DP[i][j] = DP[i-1][j] + DP[i][j-1] + arr[i][j] - DP[i-1][j-1];
        }
    }
    while(M > 0)
    {
        pair<int,int> p1, p2;
        cin >> p1.first >> p1.second >> p2.first >> p2.second;
        // 합 구하기
        int sum = DP[p2.first][p2.second] - DP[p2.first][p1.second - 1] - DP[p1.first - 1][p2.second] + DP[p1.first - 1][p1.second - 1];
        results.push_back(sum);
        M--;
    }
    for(int i=0; i<results.size(); i++)
    {
        cout << results[i] << "\n";
    }
}