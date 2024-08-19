#include <iostream>
#include <queue>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N; 
    cin >> N;
    priority_queue<int, vector<int>, greater<int>> q;
    while(N-- > 0)
    {
        int x;
        cin >> x;
        if(x==0)
        {
            // pop
            if(q.empty()) cout << "0\n";
            else{
                cout << q.top() << "\n";
                q.pop();
            }
        }
        else
        {
            q.push(x);
        }
    }
}