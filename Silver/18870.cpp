#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;
vector<int> nums; // nums[i].first = 원래 숫자, nums[i].second = 압축한 뒤 숫자
vector<int> sorted_nums;
map<int,int> compressed_num;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N;
    cin >> N;
    for(int i=0; i<N; i++)
    {
        int tmp;
        cin >> tmp;
        nums.emplace_back(tmp);
        sorted_nums.emplace_back(tmp);
    }
    sort(sorted_nums.begin(), sorted_nums.end());
    int idx = 0;
    for(int i=0; i<N; i++)
    {
        compressed_num.insert({sorted_nums[i], idx});
        if(i == 0 || sorted_nums[i-1] != sorted_nums[i]) idx++;
    }
    
    for(int i=0; i<N; i++)
    {
        cout << compressed_num[nums[i]] << " ";
    }
}