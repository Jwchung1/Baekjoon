// 이분탐색의 start, end 갱신 조건과 갱신값을 설정하는 것도 중요하고,
// 종료조건을 설정하는 것도 중요하다. 밑 주석 설명 참조
// 근데 존재하지 않는 간격이 답이 될 수 있지 않을까 하는 의문은 사라지지 않았다. 

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> x;
vector<int> dx; // 첫번째 집에서 다음 집들로의 간격을 담은 벡터

int main()
{
    int N, C;
    cin >> N >> C;
    for(int i=0; i<N; i++)
    {
        int tmp;
        cin >> tmp;
        x.push_back(tmp);
    }
    sort(x.begin(), x.end());
    
    // 1에서 최대간격 사이를 이분탐색해서 최적해 찾을 거임.
    int start = 0;
    int end = x.back() - x[0];
    
    int answer = -1;
    while(true)
    {
        int mid = (start+end)/2; // mid가 이번에 테스트하는 간격
        int numInstalled = 1;
        int pivotHouse = 0;
        for(int i=0; i<N; i++)
        {
            if(x[i] - x[pivotHouse] >= mid){
                numInstalled++;
                pivotHouse = i;
            }
        }
        // 여기서 start랑 end를 mid +- 1로 설정하는 이유는, start = mid나 end = mid로 이전 mid에 겹치게 설정할 경우, mid값이 갱신이 안되는 상황이 발생함.
        // 예를 들어 s = m = 2, e = 3이고 첫번째 조건을 만족한 경우, s값에 변화가 생기지 않아서 영원히 종료 조건에 다다를 수 없다. 
        if(numInstalled >= C) {
            // 되긴하는데 더 늘릴 수 있는지 확인
            answer = max(answer, mid);
            start = mid+1;
        }
        else{
            // 간격이 너무 넓다는 뜻
            end = mid-1;
        }
        if(end < start) break; // 무조건 이 조건이어야함. end <= start 이거 안됨. start, end, mid 모두 다 같은 경우가 최적해가 될 수 있다. 시도해보는 마지막 경우의수. 
    }
    cout << answer;
}