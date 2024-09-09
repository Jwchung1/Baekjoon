// 틀린이유: 입력에 대해 바로바로 결과를 출력해서 틀림. answer 벡터에 저장해놨다가 한번에 출력하니까 맞음.

#include <iostream>
#include <vector>
using namespace std;
long long DP[101];
vector<long long> answer;
int main()
{
    int T;
    cin >> T;
    DP[1] = 1;
    DP[2] = 1;
    DP[3] = 1;
    DP[4] = 2;
    DP[5] = 2;
    for(int i=6; i<=100; i++)
    {
        DP[i] = DP[i-1] + DP[i-5];
    }
    for(int i=0; i<T; i++)
    {
        int N;
        cin >> N;
        answer.push_back(DP[N]);
    }
    for(int i=0; i<T; i++)
    {
        cout << answer[i] << "\n";
    }
}