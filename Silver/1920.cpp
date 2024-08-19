//ios::sync_with_stdio(0);
//    cin.tie(0);
//    cout.tie(0); 이거 안넣었다고 통과 안되는건 좀 아니지않나..
// Map, unordered_set 중에는 unordered_set이 더 빠르다.

#include <iostream>
#include <map>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N,M;
    map<int,int> Map;
    cin >> N;
    for(int i=0; i<N; i++)
    {
        int tmp;
        cin >> tmp;
        Map.insert({tmp,1});
    }
    cin >> M;
    for(int i=0; i<M; i++)
    {
        int tmp;
        cin >> tmp;
        cout << Map[tmp] << "\n";
    }
}