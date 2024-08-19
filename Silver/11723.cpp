#include <iostream>
#include <set>

using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int M;
    cin >> M;
    set<int> s;
    while(M--)
    {
        string op;
        int param;
        cin >> op;
        if(op == "add")
        {
            cin >> param;
            s.insert(param);
        }
        else if(op == "check")
        {
            cin >> param;
            if(s.find(param) != s.end()) cout << "1\n";
            else cout << "0\n";
        }
        else if(op == "remove")
        {
            cin >> param;
            s.erase(param);
        }
        else if(op == "toggle")
        {
            cin >> param;
            if(s.find(param) != s.end()) s.erase(param);
            else s.insert(param);
        }
        else if(op == "all")
        {
            for(int i=1; i<=20; i++) s.insert(i);
        }
        else if(op == "empty")
        {
            s.clear();
        }
    }
}