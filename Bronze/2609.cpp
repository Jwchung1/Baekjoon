#include <iostream>
using namespace std;
int main()
{
    int a,b;
    cin >> a >> b;
    int start = min(a, b);
    for(int i=start; i>=1; i--){
        if(a%i ==0 && b%i == 0) {
            cout << i << "\n";
            break;
        }
    }
    int mult = 1;
    while(true){
        if(start*mult%a == 0 && start*mult%b == 0){
            cout << start*mult;
            return 0;
        }
        mult++;
    }
}