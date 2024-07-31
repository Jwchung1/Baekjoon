#include <iostream>
#include <vector>

using namespace std;

int N, M;
int seats[40];
int DP[40];
int main()
{
    cin >> N;
    cin >> M;

    for(int i=0; i<M; i++)
    {
        int tmp;
        cin >> tmp;
        seats[tmp-1] = 1;
    }

    vector<int> cont_seats;
    int cnt = 0;

    for(int i=0; i<N; i++)
    {
        if(seats[i] == 0) cnt++;
        else if(seats[i] == 1)
        {
            cont_seats.push_back(cnt);
            cnt = 0;
        }
    }

    if(cnt != 0) cont_seats.push_back(cnt);

    DP[0] = 1;
    DP[1] = 1;
    DP[2] = 2;
    for(int i=3; i<=N; i++)
    {
        DP[i] = DP[i-1] + DP[i-2];
    }

    int total = 1;
    for(int i=0; i<cont_seats.size(); i++)
    {
        total *= DP[cont_seats[i]];
    }
    cout << total;
}