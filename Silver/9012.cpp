#include <iostream>
#include <stack>
#include <string>
using namespace std;
int main()
{
    int T;
    cin >> T;
    while(T-->0)
    {
        string s;
        cin >> s;
        stack<char> stk;
        for(auto c : s)
        {
            if(stk.empty()) stk.push(c);
            else
            {
                if(stk.top() == '(' && c == ')'){
                    stk.pop();
                }
                else stk.push(c);
            }
        }
        string answer = "NO";
        if(stk.empty()) answer = "YES";
        cout << answer << "\n";
    }
}