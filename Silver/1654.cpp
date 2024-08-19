// 이분탐색으로 찾는 시간을 줄이는 문제!! 오버플로우도 조심하자!

#include <iostream>
#include <vector>
using namespace std;
int K, N;
int main()
{
    cin >> K >> N;
    vector<long> Lines;
    for(int i=0; i<K; i++)
    {
        long a;
        cin >> a;
        Lines.push_back(a);
    }
    long prev_length = 1;

    long length = 0;
    long add_amount = 1;

    int answer;
    while(true)
    {
        long su = 0;
        prev_length = length;
        length += add_amount;
        for(auto line : Lines)
        {
            su += line/length;
        }
        if(su < N)
        {
            if(add_amount == 1){
                answer = prev_length;
                break;
            }
            length = prev_length;
            add_amount = 1;

        }
        else if(su >= N)
        {
            add_amount *= 2;
        }
        

    }
    cout << answer;
}