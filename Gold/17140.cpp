#include <iostream>
using namespace std;
int A[4][4];
int main()
{
    int r,c,k;
    cin >> r >> c >> k;
    for(int i=0; i<3; i++)
    {

    }
    int answer = -1;

    for(int t=0; t<100; t++)
    {
        if(A[r][c] == k){
            answer = t;
            break;
        }
    }
}