#include <iostream>
#include <string>
#include <vector>
using namespace std;

string s1, s2;
int dp[1001][1001]; // dp[i][j]: i까지의 s1과 j까지의 s2의 lcs 길이
int dir[1001][1001]; // 1: 좌에서 가져옴, 2: 상에서 가져옴, 3: 좌상(대각선)에서 가져옴

void printDp()
{
    for(int i=0; i<s1.size(); i++)
    {
        for(int j=0; j<s2.size(); j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << "\n";
    }
}
void printDir()
{
    for(int i=0; i<s1.size(); i++)
    {
        for(int j=0; j<s2.size(); j++)
        {
            cout << dir[i][j] << " ";
        }
        cout << "\n";
    }
}
int main()
{
    
    cin >> s1 >> s2;
    s1.insert(0, "0"); // 인덱스 맞추기 1부터 시작하게
    s2.insert(0, "0");
    pair<int,int> maxPos;
    int maxLength = 0;
    for(int i=1; i<s1.size(); i++)
    {
        for(int j=1; j<s2.size(); j++)
        {
            if(s1[i] == s2[j])
            { // 같으면 좌상 + 1
                dp[i][j] = dp[i-1][j-1] + 1;
                dir[i][j] = 3;
            }
            else
            { // 다르면 좌나 상 중 큰거 가져옴
                if(dp[i][j-1] > dp[i-1][j])
                {
                    dp[i][j] = dp[i][j-1];
                    dir[i][j] = 1;
                }
                else
                {
                    dp[i][j] = dp[i-1][j];
                    dir[i][j] = 2;
                }
            }
            if(maxLength < dp[i][j])
            {
                maxLength = dp[i][j];
                maxPos = {i,j};
            }
        }
    }
    // printDp();
    // cout << "\n";
    // printDir();
    int x = maxPos.first;
    int y = maxPos.second;
    vector<char> answer;
    while(true)
    {
        if(x == 0 || y == 0) break;
        if(dir[x][y] == 1){
            y--;
        }
        else if(dir[x][y] == 2){
            x--;
        }
        else if(dir[x][y] == 3){
            answer.push_back(s1[x]);
            x--;
            y--;
        }
    }
    cout << maxLength << "\n";
    if(maxLength == 0) return 0;
    for(int i=answer.size()-1; i>=0; i--)
    {
        cout << answer[i];
    }
}