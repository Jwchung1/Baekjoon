#include <iostream>
using namespace std;
int main()
{
    int N;
    cin >> N;
    int stack[100001];
    int stack_size = 0;
    while(N-->0)
    {
        string op;
        cin >> op;
        if(op == "push")
        {
            int a;
            cin >> a;
            stack[stack_size++] = a;
        }
        else if(op == "top")
        {
            if(stack_size == 0) cout << "-1\n";
            else cout << stack[stack_size - 1] << "\n";
        }
        else if(op == "size")
        {
            cout << stack_size << "\n";
        }
        else if(op == "empty")
        {
            if(stack_size == 0) cout << "1\n";
            else cout << "0\n";
        }
        else if(op == "pop")
        {
            if(stack_size == 0) cout << "-1\n";
            else{
                cout << stack[stack_size - 1] << "\n";
                stack_size--;
            }
            
        }
    }
}