// 틀린 이유: 두 문자열의 길이가 같다는 얘기는 없었따!!!!!!!!!!!!!!!!!!!!!!

#include <iostream>
#include <string>
using namespace std;

string s1;
string s2;
int DP[1002][1002];
int main()
{
    cin >> s1;
    cin >> s2;
    int N = s1.length();
    int M = s2.length();
    for(int i=1; i<=N; i++)
    {
        for(int j=1; j<=M; j++)
        {
            if(s1[i-1] == s2[j-1])
            {
                DP[i][j] = DP[i-1][j-1] + 1;
            }
            else
            {
                DP[i][j] = max(DP[i-1][j], DP[i][j-1]);
            }
        }
    }
    cout << DP[N][M];
}