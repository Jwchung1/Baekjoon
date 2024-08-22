#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int N, K;
    cin >> N >> K;
    vector<int> v;
    v.resize(N+1);
    for(int i=1; i<=N; i++)
    {
        v[i] = i;
    }
    v[0] = N;
    int idx = 1;
    int cnt = 0;
    int dead = 0;
    vector<int> seq;
    while(dead < N)
    {
        idx = idx%N;
        if(v[idx] != -1){
            cnt++;
            if(cnt == K){
                dead++;
                cnt = 0;
                seq.emplace_back(v[idx]);
                v[idx] = -1;
            }
        }
        idx++;
    }
    cout << "<";
    for(int i=0; i<seq.size(); i++)
    {
        if(i != seq.size()-1) cout << seq[i] << ", ";
        else cout << seq[i];
    }
    cout << ">";
}