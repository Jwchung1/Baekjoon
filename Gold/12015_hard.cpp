// 뒤죽박죽 섞는게 가능한 이유: 순서가 꼬이게 중간원소를 변경해도, 어차피 그게 의미가 있으려면 LIS의 끝부분 원소까지 변경이 일어나는 수밖에 없는데
// 그 경우엔, LIS 끝부분 원소까지 순서에 맞게 배열이 다시 되기 떄문에 문제가 없다. 
// 끝부분까지 갱신이 일어나지 않는 경우엔, 어차피 LIS 그 자체가 아니라 길이만 관심이 있는거라 상관이 없다.

// 이분탐색으로 찾는 값에 따라 종료 조건과 start, end 갱신이 달라진다.
// 이 문제의 경우 이분탐색으로 key보다 큰 값 중 가장 작은 값을 찾는 것이 목표이므로
// mid 오른쪽 영역으로 갈때는 start = mid + 1을 해주지만,
// mid 왼쪽 영역으로 갈때는 end = mid로 해준다.
// mid <= key인 경우에는 오른쪽으로 가야함.


#include <iostream>
#include <vector>
using namespace std;
int A[1000001];
int main()
{
    int N;
    int answer = 0;
    cin >> N;
    for(int i=0; i<N; i++)
    {
        cin >> A[i];
    }

    vector<int> LIS;
    LIS.push_back(A[0]);
    for(int i=1; i<N; i++)
    {
        if(LIS.back() < A[i]) LIS.push_back(A[i]);
        else{
            int start = 0;
            int end = LIS.size() - 1;
            int mid;
            while(true){
                mid = (start+end)/2;
                if(A[i] > LIS[mid]) start = mid+1;
                else end = mid;
                if(start >= end) break;
            }
            LIS[end] = A[i];
        }
    }
    cout << LIS.size();
}

// 10 20 40 25 20 40 50 30 70 85 31 32 33 34 35 36
// 10 20    25    40 50 
// 10 20    25    30 50    70 85
// 10 20    25    30 31    32 33          34 35 36
