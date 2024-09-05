// 이분탐색 알고리즘은 맞았음. end와 start중 어떤것을 조작하느냐에 대한 기준은 문제가 요구하는 답에 따라 다름.
// 가능한 최대의 최적값을 찾는거면, 같을때도 올리고, 작을때도 올려야됨.
// 가능한 최소의 최적값을 찾는거면, 같을때도 내리고, 작을때도 내려야됨.
// 틀린이유는 start = v의 최소값으로 해서.
// 반례: 100 100 100 100 하고 총예산이 4면, 100에서 100사이에서 이분탐색을 하는데 총예산이 작아서 만족을 못함.
// 따라서 start는 1로 잡고 end를 v의 최대값으로 잡는게 맞음. start는 앵간하면 최적화하려고 하지말고 그냥 1로 잡는게 좋을듯함.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;
int main()
{
    int N, M;
    cin >> N;
    for(int i=0; i<N; i++)
    {
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }
    cin >> M;
    sort(v.begin(), v.end());
    int start = 1; // 얘가 문제였네. 예산이 매우 작은 경우가 반례가 됨.
    int end = v.back();
    // 상한액을 이분탐색해서 최적해를 찾을거임
    int mid;
    int answer = 0;
    while(true)
    {
        mid = (start+end)/2;
        // 예산 총액 계산
        int sum = 0;
        for(int i=0; i<v.size(); i++)
        {
            sum += min(mid, v[i]);
        }

        if(sum > M) end = mid-1;
        else{
            answer = max(answer, mid);
            start = mid+1;
        }
        if(start > end) break;
    }
    cout << answer;
}