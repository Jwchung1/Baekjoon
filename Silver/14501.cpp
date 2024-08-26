// else 조건 없어서 틀렸음

#include <iostream>
using namespace std;

pair<int,int> talks[16];
int DP[16]; // i일부터 했을떄 얻을 수 있는 최대 이익

int main()
{
    int N;
    cin >> N;
    for(int i=1; i<=N; i++)
    {
        int T, P;
        cin >> T >> P;
        talks[i] = {T,P};
    }

    for(int i=N; i>=1; i--)
    {
        int t = talks[i].first;
        int p = talks[i].second;
        // 끝나는 날이 N+1일이면 괜찮음
        if(i + t <= N+1){
            DP[i] = max(p + DP[i+t], DP[i+1]);
        }
        else{ // 이 조건이 없으면, 해당 날짜에 받은 일이 데드라인 밖이라는 이유로 DP가 계산이 안됨.
            DP[i] = DP[i+1];
        }
    }
    cout << DP[1];
}