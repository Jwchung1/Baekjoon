#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int N;
void rec(int height, int start, int dest, int mid)
{
    if(height == 0) return;
    rec(height - 1, start, mid, dest); // h-1층을 start에서 mid로 옮기고,
    cout << start << " " << dest << "\n"; // 가장 밑 원판을 dest에 놓고
    rec(height - 1, mid, dest, start); // h-1층을 다시 mid에서 dest로 옮기기
}
int main()
{
    cin >> N;
    // 5층짜리를 dest로 옮기는건, 4층짜리를 mid으로 옮기고, 5번째 원판을 dest에 놓고, 4층짜리를 dest로 옮기는 것.
    // 4층짜리를 목적지로 옮기는건, 3층짜리...
    // 3층짜리를..
    // 2층...
    // 1층짜리를 목적지로 옮기는건, 1번째 원판을 목적지에 놓는것.
    int cnt = pow(2,N) - 1;
    cout << cnt << "\n";
    rec(N, 1, 3, 2);
}