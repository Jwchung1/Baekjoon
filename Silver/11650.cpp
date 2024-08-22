#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(pair<int,int> p1, pair<int,int> p2)
{
    if(p1.first == p2.first) return p1.second < p2.second;
    return p1.first < p2.first;
}

int main()
{
    int N;
    cin >> N;
    vector<pair<int,int>> v;
    for(int i=0; i<N; i++)
    {
        int a,b;
        cin >> a >> b;
        v.emplace_back(make_pair(a,b));
    }
    sort(v.begin(), v.end(), cmp);
    for(auto p: v)
    {
        cout << p.first << " " << p.second << "\n";
    }
}