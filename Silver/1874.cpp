#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;
int main()
{
    int n;
    cin >> n;

    vector<int> sequence; // 수열
    queue<int> numbers; // 스택에 넣을 숫자들 저장해 놓는 곳
    vector<char> result;
    for(int i=1; i<=n; i++)
    {
        numbers.push(i);
        int num;
        cin >> num;
        sequence.push_back(num);
    }
    stack<int> stk;
    for(int i=0; i<n; i++)
    {
        int cur_num = sequence[i];
        while(true)
        {
            if(stk.empty() || stk.top() < cur_num) {
                stk.push(numbers.front());
                numbers.pop();
                result.push_back('+');
            }
            else if(stk.top() == cur_num){
                stk.pop();
                result.push_back('-');
                break;
            }
            else{
                cout << "NO\n";
                return 0;
            }
        }
    }
    for(int i=0; i<result.size(); i++)
    {
        cout << result[i] << "\n";
    }
}