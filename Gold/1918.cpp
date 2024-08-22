// 연산자 아닌애는 그냥 출력
// 연산자면 나보다 우선도 높은애 스택에서 다 내보내고 들어감 [먼저들어온*/ > 나중에들어온 */ > 먼저들어온 +- > 나중에들어온 +- > (]
// 솔루션 본 문제 **
#include <iostream>
#include <string>
#include <stack>
using namespace std;
int main()
{
    string s;
    cin >> s;
    stack<char> stk;
    for(auto c: s)
    {
        if(c!= '*' && c!='/' && c!='+' && c!='-' && c!='(' && c!=')'){
            cout << c;
            continue;
        }
        else{
            if(c == '(') stk.push(c);
            else if(c == ')'){
                while(stk.top() != '('){
                    cout << stk.top();
                    stk.pop();
                }
                stk.pop();
            }
            else if(c == '*' || c == '/'){
                while(!stk.empty() && (stk.top() == '*' || stk.top() == '/')){ // 같은 곱나눔이면 먼저온 곱나눔이 우선도가 높으니까 출력하고 팝 내 앞이 나보다 우선도 낮은놈일때까지
                    cout << stk.top();
                    stk.pop();
                }
                stk.push(c);
            }
            else if(c == '+' || c == '-'){
                while(!stk.empty() && stk.top() != '('){ // 늦게 들어온 +-는 같은 연산자내에서 우선도 가장 낮으니까, ( 나올때까지 다 나가라고 하고 들어감.
                    cout << stk.top();
                    stk.pop();
                }
                stk.push(c);
            }
        }
    }

    while(!stk.empty()){
        cout << stk.top();
        stk.pop();
    }
}