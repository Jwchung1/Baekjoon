#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    int N;
    vector<int> cards;
    cin >> N;
    for(int i=0; i<N; i++)
    {
        int a;
        cin >> a;
        cards.emplace_back(a);
    }
    sort(cards.begin(), cards.end());
    int M;
    cin >> M;
    for(int i=0; i<M; i++)
    {
        int a;
        cin >> a;
        cout << upper_bound(cards.begin(), cards.end(), a) - lower_bound(cards.begin(), cards.end(), a) << " ";
    }
}