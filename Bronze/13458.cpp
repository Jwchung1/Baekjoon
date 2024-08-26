#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int main()
{
    int N;
    cin >> N;
    vector<int> room;
    for(int i=0; i<N; i++)
    {
        int A;
        cin >> A;
        room.emplace_back(A);
    }
    int B,C;
    cin >> B >> C;
    long long answer = 0;
    for(int i=0; i<N; i++)
    {
        room[i] -= B;
        answer++;
        if(room[i] > 0)
        {
            answer += room[i]/C;
            if(room[i]%C != 0){
                answer++;
            }
        }
    }
    
    cout << answer;
}