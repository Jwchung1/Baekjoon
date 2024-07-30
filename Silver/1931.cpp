#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<pair<int,int>> v;

// sort() 디폴트가 첫번째 요소 같으면 두번째 요소도 고려하게 되어있음. 
bool comp(pair<int,int> p1, pair<int,int> p2)
{
    if(p1.second == p2.second) return p1.first < p2.first; // 끝나는 시간이 같으면 먼저 시작하는애가 앞으로 오게 *이 한줄이 없어서 틀렸음.
    // 반례
    // 3
    // 4 4
    // 3 4
    // 2 4
    return p1.second < p2.second;
}

int main()
{
    cin >> N;
    for(int i=0; i<N; i++)
    {
        pair<int,int> tmp;
        cin >> tmp.first >> tmp.second;
        v.push_back(tmp);
    }
    // 끝나는시간 빠른 순으로 정렬
    sort(v.begin(), v.end(), comp);
    
    int count = 1;
    int cur_time = v[0].second;
    for(int i=1; i<N; i++)
    {
        // 현재 시간보다 시작시간이 늦거나 같은 애를 스케줄
        if(cur_time <= v[i].first)
        {
            count++;
            cur_time = v[i].second;
        }
    }

    cout << count;
}