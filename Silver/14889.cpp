// 시간초과가 떴던 브루트포스 문제. 재귀로 팀을 만들때, 이미 지나친 선수부터 반복문을 돌지 않고, 직전에 뽑은 선수 다음부터 돈다. 이렇게 하면 중복 없이 모든 팀 경우의 수가 나온다.
// 모든 팀 경우의수는 대칭구조로 나온다. 1,2,3,4,5,6 경우의 수가 있으면, 1-6, 2-5, 3-4 이런식으로 team1-team2 관계가 성립.
// 위 사실을 모르고 짜서 Maketeam에서 필요 시간의 2배를 쓰고, 전력차 계산에서도 for문 하나를 더 중첩시켜야했다. -> 시간초과

#include <iostream>
#include <vector>
#include <set>

using namespace std;

int N;
int S[21][21];

vector<set<int>> teams;
vector<int> people(21,0);// 0이면 아직 안뽑음, 1이면 이미 뽑음  크기 21짜리 0으로 초기화한 벡터

void MakeTeam(set<int> team, int find_start)
{
    if(team.size() == N/2)
    {
        teams.push_back(team);
    }
    for(int i=find_start; i<=N; i++)
    {
        if(team.find(i) == team.end())
        {
            // team에 없는 애면 뽑고 재귀
            team.insert(i);
            MakeTeam(team, i+1);
            team.erase(i);
        }
    }
}

int main()
{
    cin >> N;
    for(int i=1; i<=N; i++)
    {
        for(int j=1; j<=N; j++)
        {
            cin >> S[i][j];
        }
    }
    // 가능한 team 경우의 수 모두 구해서 teams에 넣기
    set<int> s;
    MakeTeam(s, 1);
    //teams로 전력차 계산하기
    int min_power_diff = INT32_MAX;
    for(int i=0; i<teams.size(); i++)
    {
        set<int> team2 = teams[teams.size() - i - 1];
        
        int team1_power = 0;
        for(int p1 : teams[i])
        {
            for(int p2: teams[i])
            {
                //printf("p1: %d, p2: %d, S[p1][p2]: %d\n", p1,p2,S[p1][p2]);
                team1_power += S[p1][p2];
            }
        }
        int team2_power = 0;
        for(int p1 : team2)
        {
            for(int p2: team2)
            {
                team2_power += S[p1][p2];
            }
        }
        int power_diff = abs(team1_power - team2_power);
        //printf("team1: %d, team2: %d, pd: %d\n", team1_power, team2_power, power_diff);
        min_power_diff = min(min_power_diff, power_diff);
    }

    cout << min_power_diff;
}