// 브루트포스로 암호문 조합을 만드는 문제.
// 조합을 만드는 문제는 재귀(DFS)로 보통 구현함.
// 재귀함수는 다음과 같은 구조. 1. 종료조건, 2. 반복문(넣고, 재귀, 뽑고)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int L, C;
vector<char> v;
vector<vector<char>> cyphers;

bool IsVowel(char c)
{
    if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') return true;
    else return false;
}

void MakeComb(int find_start, vector<char> cypher, int consonants, int vowels)
{
    if(cypher.size() >= L)
    {
        if(consonants >= 2 && vowels >= 1) cyphers.push_back(cypher);
        return;
    }
    else
    {
        for(int i=find_start; i<C; i++)
        {
            cypher.push_back(v[i]);
            if(IsVowel(v[i])) MakeComb(i+1, cypher, consonants, vowels+1);
            else MakeComb(i+1, cypher, consonants+1, vowels);
            cypher.pop_back();
        }
    }
}

int main()
{
    cin >> L >> C;
    for(int i=0; i<C; i++)
    {
        char tmp;
        cin >> tmp;
        v.push_back(tmp);
    }
    sort(v.begin(), v.end());
    vector<char> tmp_v;
    MakeComb(0, tmp_v, 0, 0);
    for(int i=0; i<cyphers.size(); i++)
    {
        for(int j=0; j<cyphers[i].size(); j++)
        {
            cout << cyphers[i][j];
        }
        cout << "\n";
    }
}