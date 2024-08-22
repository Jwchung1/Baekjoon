#include <iostream>
#include <string>
using namespace std;
int main()
{
    int N;
    int q[10002];
    int front = 1;
    int rear = 1;
    cin >> N;
    while(N--)
    {
        string s;
        int a;
        cin >> s;
        if(s == "push"){
            cin >> a;
            q[rear] = a;
            rear++;
        }
        else if(s == "pop"){
            if(rear - front == 0) cout << "-1\n";
            else{
                cout << q[front] << "\n";
                front++;
            }
        }else if(s == "size"){
            cout << rear - front << "\n";
        }else if(s == "empty"){
            if(rear - front == 0) cout << "1\n";
            else cout << "0\n";
        }else if(s == "front"){
            if(rear - front == 0) cout << "-1\n";
            else cout << q[front] << "\n";
        }else if(s == "back"){
            if(rear - front == 0) cout << "-1\n";
            else cout << q[rear-1] << "\n";
        }
    }
}