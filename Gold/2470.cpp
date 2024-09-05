// 이분 탐색 문제는 먼저 무엇을 이분탐색해야하는지 찾아야한다.
    // 원소 하나에 대해, 그 원소와의 합이 가장 0과 가까운 것을 찾고, 그것의 최소값을 갱신해나간다.
    // 라고 생각했는데 이분탐색이 아니라 투포인터로 간단하게 풀리는 문제였다.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;
int main()
{
    int N;
    cin >> N;
    for(int i=0; i<N; i++)
    {
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }
    sort(v.begin(), v.end());
    // 이분 탐색 문제는 먼저 무엇을 이분탐색해야하는지 찾아야한다.
    // 원소 하나에 대해, 그 원소와의 합이 가장 0과 가까운 것을 찾고, 그것의 최소값을 갱신해나간다.
    // 라고 생각했는데 이분탐색이 아니라 투포인터로 간단하게 풀리는 문제였다.
    int minSum = INT32_MAX;
    vector<int> answer;
    answer.resize(2);
    
    // 투포인터로 탐색.
    // 정렬된 벡터의 양끝에서 시작해서, 0보다 커졌으면 위쪽을 내리고, 0보다 작으면 아래쪽을 올린다. 
    int start = 0;
    int end = v.size() -1;
    while(start < end)
    {
        int pSum = v[start] + v[end];
        if(abs(pSum) < minSum){
            minSum = abs(pSum);
            answer[0] = v[start];
            answer[1] = v[end];
        }

        if(pSum < 0) start++;
        else if(pSum > 0) end--;
        else break;
    }
    cout << answer[0]<< " " << answer[1];
}
// -99 -2 -1 4 98