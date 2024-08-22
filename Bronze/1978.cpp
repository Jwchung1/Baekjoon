#include <iostream>
using namespace std;
int main()
{
    int N;
    cin >> N;
    int answer = 0;
    bool IsPrime[1001];
    fill_n(IsPrime, 1001, true);
    IsPrime[1] = false;
    for(int i=2; i<=32; i++)
    {
        int mult = 2;
        while(i*mult <=1000){
            IsPrime[i*mult] = false;
            mult++;
        }
    }
    for(int i=0; i<N; i++)
    {
        int a;
        cin >> a;
        if(IsPrime[a] == true) answer++;
    }
    cout << answer;
}