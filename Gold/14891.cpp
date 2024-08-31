// 간단한 구현, 시뮬레이션 문제. 톱니바퀴 숫자가 1,2,3,4로 주어지는데 0,1,2,3 배열에 담고 있어서 세그 폴트 났었다. 

#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <cmath>
using namespace std;
vector<string> gears;

void Rotate(int gear, int dir)
{
    if(dir == 1)
    {
        char tmp = gears[gear][7];
        for(int i=6; i>=0; i--)
        {
            gears[gear][i+1] = gears[gear][i];
        }
        gears[gear][0] = tmp;
    }
    else if(dir == -1)
    {
        char tmp = gears[gear][0];
        for(int i=1; i<=7; i++)
        {
            gears[gear][i-1] = gears[gear][i];
        }
        gears[gear][7] = tmp;
    }
}

void PrintGear()
{
    for(int i=0; i<4; i++)
    {
        cout << gears[i] << "\n";
    }
}

int main()
{
    
    for(int i=0; i<4; i++)
    {
        string s;
        cin >> s;
        gears.push_back(move(s));
    }

    int K;
    cin >> K;
    queue<pair<int,int>> rotations;
    for(int i=0; i<K; i++)
    {
        int a,b;
        cin >> a >> b;
        rotations.push({a,b});
    }
    while(!rotations.empty())
    {
        int gearToRotate = rotations.front().first - 1;
        int direction = rotations.front().second;
        rotations.pop();

        int gearDir[4] = {0,}; // 0이 안돌리기, 1이 시계방향, -1이 반시계방향
        gearDir[gearToRotate] = direction;
        // 돌릴 기어 왼쪽으로 돌릴애들 방향 정하기
        for(int i=gearToRotate-1; i>=0; i--)
        {
            if(gears[i][2] != gears[i+1][6]) // 극이 다르면 반대방향으로 회전함
            {
                gearDir[i] = gearDir[i+1]*(-1);
            }
        }
        // 돌릴 기어 오른쪽으로 돌릴애들 방향 정하기
        for(int i=gearToRotate+1; i<4; i++)
        {
            if(gears[i][6] != gears[i-1][2])
            {
                gearDir[i] = gearDir[i-1]*(-1);
            }
        }
        // 정한 방향으로 돌리기
        for(int i=0; i<4; i++)
        {
            Rotate(i, gearDir[i]);
        }
    }


    // 12시 방향 값 더하기
    int score = 0;
    for(int i=0; i<4; i++)
    {
        if(gears[i][0] == '1')
        {
            score += pow(2,i);
        }
    }
    cout << score;
}