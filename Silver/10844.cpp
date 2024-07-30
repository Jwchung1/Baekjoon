// 

#include <iostream>

using namespace std;

int N;
long long StairNumber[10][101]; // StairNumber[i,j] = i로 시작하는 j자리 계단수의 갯수
int main()
{
    cin >> N;
    // 초기화
    for(int i=0; i<10; i++)
    {
        StairNumber[i][1] = 1;
    }

    for(int j=2; j<=N; j++)
    {
        // j는 자릿수
        for(int i=0; i<10; i++)
        {
            // i는 시작하는 숫자
            if(i==0)
            {
                StairNumber[i][j] = StairNumber[i+1][j-1];
            }
            else if(i==9)
            {
                StairNumber[i][j] = StairNumber[i-1][j-1];
            }
            else
            {
                StairNumber[i][j] = StairNumber[i-1][j-1] + StairNumber[i+1][j-1];
            }
            StairNumber[i][j] %= 1000000000;
        }
    }
    
    long long sum = 0;
    // 0으로 시작하는 계단수 빼기 위해 1~9만 sum에 합침
    for(int i=1; i<10; i++)
    {
        sum += StairNumber[i][N];
    }
    sum = sum % 1000000000;
    cout << sum;
}