// 백트래킹 문제. 이 문제의 포인트는 중복수열을 어떻게 판단할 것이냐 이다.
// 같은 레벨에서 이미 사용한 숫자를 한번 더 사용하면 중복 수열이 된다.
// ex) 1 2 3 3 4 에서, 1 2 3 x x과 1 2 x 3 x
// 이걸 해결하기 위해 해당 레벨에 tmp라는 변수를 두고, 직전에 사용한 숫자를 저장하여, 이번에 넣을 숫자가 이미 사용했던 숫자면 넣지 않는다.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N,M;
vector<int> nums;
vector<vector<int>> combs;
int visited[9]; // 해당 인덱스 썼는지
void MakeComb(vector<int>& v)
{
    if(v.size() == M){
        combs.push_back(v);
        return;
    }
    int prev = 0;
    for(int i=0; i<N; i++){
        if(visited[i] == 0 && prev != nums[i])
        {
            v.push_back(nums[i]);
            visited[i] = 1;
            prev = nums[i];
            MakeComb(v);
            v.pop_back();
            visited[i] = 0;
        }
    }
}

int main()
{
    cin >> N >> M;
   
    for(int i=0; i<N; i++)
    {
        int tmp;
        cin >> tmp;
        nums.emplace_back(tmp);
        
    }
    sort(nums.begin(), nums.end());
    vector<int> tmp;
    MakeComb(tmp);
    for(auto c:combs){
        for(auto i:c){
            cout << i << " ";
        }
        cout << "\n";
    }
}