#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool cmp(pair<pair<int,string>,int> p1, pair<pair<int,string>,int> p2)
{
    if(p1.first.first == p2.first.first){
        return p1.second < p2.second;
    }
    return p1.first.first < p2.first.first;
}

int main()
{
    int N;
    cin >> N;
    vector<pair<pair<int,string>,int>> v;
    for(int i=0; i<N; i++)
    {
        int age;
        string name;
        cin >> age >> name;
        v.push_back({{age,name},i});
    }
    sort(v.begin(), v.end(), cmp);
    for(auto p: v)
    {
        cout << p.first.first << " " << p.first.second << "\n";
    }
}