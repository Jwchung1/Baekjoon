// **중요** 순열을 찾는 문제!!
// 조합을 찾을땐 find_start를 두고 거기서부터 돌았지만,
// 순열은 순서도 고려하므로, 0부터 찾되, visited를 따로 둬서 중복이 안들어가게 해야한다.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
vector<int> nums;
vector<vector<int>> seqs;
int visited[10001];
void MakeSeq(vector<int>& v)
{
    if(v.size() == M){
        seqs.push_back(v);
        return;
    }
    for(int i=0; i<N; i++)
    {
        if(visited[nums[i]] == 0)
        {
            v.push_back(nums[i]);
            visited[nums[i]] = 1;
            MakeSeq(v);
            v.pop_back();
            visited[nums[i]] = 0;
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
        nums.push_back(tmp);
    }
    sort(nums.begin(), nums.end());
    vector<int> tmp;
    MakeSeq(tmp);
    
    for(auto s: seqs)
    {
        for(auto i:s)
        {
            cout << i << " ";
        }
        cout << "\n";
    }
}