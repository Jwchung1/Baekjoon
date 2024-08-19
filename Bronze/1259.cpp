#include <iostream>
#include <vector>
#include <stack>
#include <string>
using namespace std;
int main()
{
    string s;
    while(true)
    {
        stack<char> stk;
        cin >> s;
        if(s == "0") break;
        int size = s.size();
        bool isOdd = size%2 == 0 ? false : true;
        for(int i=0; i<size; i++)
        {
            if(isOdd && i==size/2) continue;
            else
            {
                if(stk.empty() || stk.top() != s[i]){
                    stk.push(s[i]);
                }
                else if(stk.top() == s[i]){
                    stk.pop();
                }
            }
        }
        if(stk.empty()) cout << "yes\n";
        else cout << "no\n";
    }
}