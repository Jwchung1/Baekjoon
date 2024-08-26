#include <iostream>
#include <vector>
using namespace std;

int N, L, answer = 0;
vector<vector<int>> Map;

int main()
{
    cin >> N >> L;
    Map.resize(N+1, vector(N+1,0));
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            cin >> Map[i][j];
        }
    }

    for(int i=0; i<N; i++)
    {
        // i행 길 확인
        int isSlope[N] = {0,}; // 이게 1이면 그 칸은 경사로 이미 있는거
        bool canCross = true;
        for(int j=0; j<N-1; j++)
        {
            // 다음 길 갈 수 있는지
            if(Map[i][j] == Map[i][j+1]){
                // 높이 같음. 그냥 통과
                continue;
            }
            else if(Map[i][j] + 1 == Map[i][j+1])
            {
                // 다음 칸이 한칸 높음. 경사로 뒤쪽으로 놓기
                for(int k=j; k>j-L; k--)
                {
                    // j칸부터 j-L+1칸까지 경사로 놓을건데, 한 칸이라도 조건 만족 못하면 false
                    if(k < 0 || Map[i][k] != Map[i][j] || isSlope[k] == 1){
                        canCross = false;
                        //cout << i << "행 뒤쪽놓기 불가\n";
                        break;
                    }
                }
                if(canCross){
                    for(int k=j; k>j-L; k--)
                    {
                        isSlope[k] = 1;
                    }
                }
            }
            else if(Map[i][j] - 1 == Map[i][j+1])
            {
                // 다음 칸이 한칸 낮음. 경사로 앞쪽으로 놓기
                for(int k=j+1; k<=j+L; k++)
                {
                    if(k >= N || Map[i][k] + 1 != Map[i][j] || isSlope[k] == 1){
                        canCross = false;
                        //cout << i << "행 앞쪽놓기 불가\n";
                        break;
                    }
                }
                if(canCross){
                    for(int k=j+1; k<=j+L; k++)
                    {
                        isSlope[k] = 1;
                    }
                }
            }
            else{
                // 높이 차이 2이상. 못감.
                canCross = false;
            }
            if(!canCross) break;
        }
        if(canCross) {
            answer++;
            //cout << i << "행 가능\n";
        }
        // i열 길 확인
        fill(isSlope, isSlope + N, 0); // 이게 1이면 그 칸은 경사로 이미 있는거
        canCross = true;
        for(int j=0; j<N-1; j++)
        {
            // 다음 길 갈 수 있는지
            if(Map[j][i] == Map[j+1][i]){
                // 높이 같음. 그냥 통과
                continue;
            }
            else if(Map[j][i] + 1 == Map[j+1][i])
            {
                // 다음 칸이 한칸 높음. 경사로 뒤쪽으로 놓기
                for(int k=j; k>j-L; k--)
                {
                    // j칸부터 j-L+1칸까지 경사로 놓을건데, 한 칸이라도 조건 만족 못하면 false
                    if(k < 0 || Map[k][i] != Map[j][i] || isSlope[k] == 1){
                        canCross = false;
                        //cout << i << "열 뒤쪽놓기 불가\n";
                        break;
                    }
                }
                if(canCross){
                    for(int k=j; k>j-L; k--)
                    {
                        isSlope[k] = 1;
                    }
                }
            }
            else if(Map[j][i] - 1 == Map[j+1][i])
            {
                // 다음 칸이 한칸 낮음. 경사로 앞쪽으로 놓기
                for(int k=j+1; k<=j+L; k++)
                {
                    if(k >= N || Map[k][i] + 1 != Map[j][i] || isSlope[k] == 1){
                        canCross = false;
                        //cout << i << "열 앞쪽놓기 불가\n";
                        break;
                    }
                }
                if(canCross){
                    for(int k=j+1; k<=j+L; k++)
                    {
                        isSlope[k] = 1;
                    }
                }
            }
            else{
                // 높이 차이 2이상. 못감.
                canCross = false;
            }
            if(!canCross) break;
        }
        if(canCross) {
            answer++;
        }
    }
    cout << answer;
}