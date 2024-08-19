// 브루트포스 조합 짜는 틀을 외워놓자. MakeCombinations
// BFS를 굳이 할 필요가 없다! 집 좌표들을 저장해놓고, 치킨집 좌표들이랑 빼봐서 가장 작은 값을 더하기만 하면된다!
// 그냥 브루트포스 문제!

#include <iostream>
#include <set>
#include <queue>
#include <vector>
#include <map>
using namespace std;

int N, M;
int town_map[50][50];
pair<int,int> dir[4] = {{0,1},{0,-1},{1,0},{-1,0}};
map<int,pair<int,int>> chicken_house; // 치킨집 번호와 좌표 매핑
vector<set<int>> combinations;
vector<int> results;
int min_result = INT32_MAX;
int chicken_house_num = 0;

void PrintTownMap()
{
    cout << "\n";
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            cout << town_map[i][j] << " ";
        }
        cout << "\n";
    }
}

void MakeCombinations(set<int> s, int find_start)
{
    if(s.size() == M)
    {
        combinations.push_back(s);
        Calculate(s);
    }
    else
    {
        for(int i=find_start; i<=chicken_house_num; i++)
        {
            s.insert(i);
            MakeCombinations(s, i+1); // i번째꺼 넣은 조합 찾기
            s.erase(i); // i번째꺼 안 넣은 조합 찾기
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    cin >> N >> M;
    
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            cin >> town_map[i][j];
            if(town_map[i][j] == 2)
            {
                chicken_house.insert({++chicken_house_num, {i,j}});
                town_map[i][j] = 0; // 일단 마을지도에는 표시 안함
            }
        }
    }
    // 치킨집 중 M개를 고르는 경우의 수를 구한다.
    set<int> tmp;
    MakeCombinations(tmp, 1);
    // 각 경우의 수에 따른 치킨거리 중 최솟값을 구한다.
    cout << min_result;
}