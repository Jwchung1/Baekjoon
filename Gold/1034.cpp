// 애드 혹 문제인데, 직관이 중요한듯하다.
// 중요한 직관은: 같은 패턴은 반드시 같이 켜진다. 다른 패턴은 절대 같이 안 켜진다.

#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

vector<string> v;
map<string, int> patterns; // 패턴, 나오는 횟수
int N, M, K;
int answer = 0;

bool CanLit(string s)
{
    // 0의 갯수가 K보다 크면 false
    // 0의 갯수가 K보다 작은경우
        // k-0의갯수 가 홀수인 경우, false
        // 짝수인경우 true
    // 0의 갯수 구하기
    int zeroNum = 0;
    for(int i=0; i<s.size(); i++)
    {
        if(s[i] == '0') zeroNum++;
    }
    if(zeroNum > K) return false;
    else{
        if((K-zeroNum)%2 == 0) return true;
        else return false;
    }
}

int main()
{
    cin >> N >> M;
    for(int i=0; i<N; i++)
    {
        string s;
        cin >> s;
        if(patterns[s]) patterns[s]++;
        else patterns[s] = 1;
        v.push_back(move(s));
    }
    cin >> K;
    // 패턴이 같은 행은 어떤 시행을 하든 동시에 켜지며 동시에 꺼진다.
    // 행의 패턴마다 킬수있는지 K와 M을 사용해 확인한다.
    // 킬수 있는 패턴중에 가장 많은 것의 갯수가 정답이다.
    // 패턴이 다른데 같이 켜질 수 있는 경우? 존재하지 않는다. 
    for(auto i = patterns.begin(); i != patterns.end(); i++)
    { // 킬수 있는지 확인
        if(CanLit(i->first)){
            answer = max(answer, i->second);
        }
    }
    cout << answer;
}