// 우선순위 큐의 custom compare 함수를 어떻게 만드는지 익혀놓자. 
// 구조체 선언 -> bool operator()(인자){} 오버로딩 -> 함수 구현
// priority_queue<자료형, 컨테이너, 구조체>
// 시간초과가 뜬 이유: 결과들을 results 벡터에 담아놨다가 한꺼번에 출력하니까 됐다. 대체 왜지 


#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int N;

struct abs_min{
    bool operator()(int a, int b){
        if(abs(a) == abs(b)) return a > b;
        return abs(a) > abs(b);
    }
};

int main()
{
    cin >> N;
    priority_queue<int, vector<int>, abs_min> abs_min_heap;
    vector<int> results;
    for(int i=0; i<N; i++)
    {
        int x;
        cin >> x;
        if(x == 0)
        {
            if(abs_min_heap.empty())
            {
                results.push_back(0);
                continue;
            }
            results.push_back(abs_min_heap.top());
            abs_min_heap.pop();
        }
        else{
            // push(x)
            abs_min_heap.push(x);
        }
    }
    for(int i=0; i<results.size(); i++)
    {
        cout << results[i] << "\n";
    }
}