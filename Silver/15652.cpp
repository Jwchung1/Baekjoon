#include <iostream>
#include <vector>
using namespace std;
int N, M;

void DFS(vector<int>& v, int start)
{
    if(v.size() == M){
        for(auto a : v)
        {
            cout << a << " ";
        }
        cout << "\n";
        return;
    }    
    for(int i=start; i<=N; i++)
    {
        v.push_back(i);
        DFS(v, i);
        v.pop_back();
    }
}

int main()
{
    cin >> N >> M;
    vector<int> tmp;
    DFS(tmp, 1);
}