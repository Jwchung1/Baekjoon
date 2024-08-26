// 투포인터 알고리즘 몰라서 찾아봤던 문제.
// 모든 부분합 순회하려고 하면 O(N^2)으로 시간초과 뜬다.
// 연속된 수들의 합이나 부분 수열의 합 문제는 투포인터 알고리즘으로 O(N)을 떠올리자.
// ***중요***

#include <iostream>
#include <vector>
using namespace std;
int seq[100001];
int main()
{
    int N, S;
    cin >> N >> S;
    for(int i=1; i<=N; i++)
    {
        cin >> seq[i];
    }
    int start = 0;
    int end = 1;
    int sum = seq[1]; // end 옮길때 더해주고, start옮길때 빼주고
    int min_length = INT32_MAX;
    while(start != end)
    {
        //printf("start: %d, end: %d\n", start, end);
        if(end == N)
        {
            if(sum >= S)
            {
                min_length = min(min_length, end - start);
            }
            start++;
            sum -= seq[start];
        }
        else if(sum < S) // 목표합보다 작으면 더해줌
        {
            end++;
            sum += seq[end];
        }
        else if(sum >= S){ // 목표합보다 크면 빼줌
            min_length = min(min_length, end - start);
            //cout << min_length << ", sum: " << sum << "\n";
            start++;
            sum -= seq[start];
            
        }
    }
    if(min_length == INT32_MAX) cout << "0";
    else cout << min_length;
}