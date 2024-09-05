#include <iostream>
#include <stack>
#include <string>
using namespace std;
int main()
{
    string s;
    cin >> s;
    // 문자열이 팰린드롬인 경우, 답은 s.size() - 1 이 두 경우로 나누면 모든 경우의 수임
    // 문자열이 팰린드롬이 아닌 경우, 답은 s.size()
    // 문자열이 모두 같은 경우, 답은 -1  이거 최우선으로 거르고
    // 문자열이 하나라도 다른경우: 이건 팰린드롬 될수도 있고 아닐 수도 있음.
    bool allSame = true;
    for(int i=0; i<s.size(); i++)
    {
        if(s[i] != s[0]){
            allSame = false;
            break;
        }
    }
    if(allSame){
        cout << "-1";
        return 0;
    }

    // 팰린드롬 확인
    int p1 = 0;
    int p2 = s.size()-1;
    while(p1 < p2)
    {
        if(s[p1] != s[p2])
        { // 팰린드롬 아닌거 확인
            cout << s.size();
            return 0;
        }
        p1++;
        p2--;
    }
    // 통과했으면 팰린드롬임
    cout << s.size() - 1;
    return 0;
}   