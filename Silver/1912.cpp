#include <iostream>
#include <vector>
using namespace std;
int N;
vector<int> v;
int DP[100001];
int main()
{
    cin >> N;
    v.push_back(0);
    for(int i=0; i<N; i++)
    {
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }
    int max_sum = INT32_MIN;
    for(int i=1; i<=N; i++)
    {
        DP[i] = max(DP[i-1] + v[i], v[i]);
        max_sum = max(max_sum, DP[i]);
    }
    cout << max_sum;
}