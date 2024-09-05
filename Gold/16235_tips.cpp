// 틀린 이유들: 
// 1. 문제 좌표 기준이 1,1부터인데, 0,0으로 풀었어서 틀렸었다.
// 2. 시간초과 해결하는게 관건이었다. 다음이 최적화 기법들
// 2-1. deadTree 큐를 만들어서 넣고 다시 빼면서 합을 해주었는데, 그럴 필요 없이 totalDeadTreeNut 변수에 더해주고 한번에 더해주면 된다.
//      while(!deadTree.empty()) -> +totalDeadTreeNut
// 2-2. nut배열은 봄에만 쓰이고 나머지 계절에는 안쓰이기 때문에, 여름,겨울의 nut조작을 한꺼번에 앞서서 해도된다. 이를 통해 이중for문 하나를 없앨 수 있다.
//      기존: 이중for문 봄, 가을, 겨울 하나씩 -> 봄, 가을 하나씩.
// 시간이 더 짧게 걸린 다른 풀이를 보면,
// 땅에 심어진 나무들을 우선순위 큐가 아닌 벡터로 받아서 정렬을 한 후, 순회한다.
// 정렬 방식 사용시, O(nlogn + n)이고,
// 우선순위 큐 방식 사용시,  O(2nlogn)이다. 
// 이게 200ms 차이까지 벌어진듯 하다. 또한 벡터로 하면 입력을 받을때도 더 빠르게 할 수 있다.
// M이 100인 경우, 우선순위큐는 모두 입력 받는데 100*log100 인데, 벡터는 그냥 100이다.

#include <iostream>
#include <vector>
#include <queue>
using namespace std;
priority_queue<int, vector<int>, greater<int>> Land[11][11]; // 그 땅에 심어진 나무들 나이순으로
queue<int> liveTree;
queue<int> deadTree;
int N, M, K;
int nut[11][11]; // 그 땅에 있는 양분
int A[11][11]; // 그 땅에 추가되는 양분
int fives[11][11]; // 그 땅의 나이가 5의 배수인 나무의 갯수

void newTree(int i, int j)
{
    if(i < 1 || i> N || j < 1 || j>N) return;
    Land[i][j].push(1);
}

int main()
{
    ios::sync_with_stdio(0);
    cout.tie(0); cin.tie(0);
    cin >> N >> M >> K;
    for(int i=1; i<=N; i++)
    {
        for(int j=1; j<=N; j++)
        {
            cin >> A[i][j];
            nut[i][j] = 5;
        }
    }
    for(int i=1; i<=M; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        Land[x][y].push(z);
    }
    // 하나의 칸에 나무가 여러개 존재 가능.
    // 양분은 본인 칸 것만 흡수 가능
    // 어린 나무부터 양분 흡수
    // 양분이 부족하면 나무 사망
    // 봄: 나무가 자신의 나이만큼 양분흡수, 나이 1 증가
    // 여름: 봄에 죽은 나무가 양분으로 변환. 죽은 나무의 나이 / 2 가 양분으로 추가
    // 가을: 나이가 5의 배수인 나무는 번식. 인접한 8개 칸에 나이 1인 나무 생성
    // 겨울: 땅에 양분을 추가 추가되는 양분은 A[r][c]
    // 정답은 K년 후의 살아있는 나무의 개수

    while(K--)
    {// 한 해 시작
        // 봄
        for(int i=1; i<=N; i++)
        {
            for(int j=1; j<=N; j++)
            {
                // 나무들 양분 흡수
                int totalDeadTreeNut = 0;
                while(!Land[i][j].empty()) // O(nlogn)
                {
                    int curTreeAge = Land[i][j].top();
                    Land[i][j].pop(); // O(logn)
                    if(nut[i][j] >= curTreeAge){
                        // 양분이 충분하면 양분 흡수
                        nut[i][j] -= curTreeAge;
                        liveTree.push(curTreeAge+1);
                    }
                    else{
                        // 양분이 자기 나이만큼 없으면 사망
                        totalDeadTreeNut += curTreeAge/2;
                    }
                }
                // 산 나무들 다시 땅에 옮겨심기
                while(!liveTree.empty()){  // O(nlogn)
                    int treeAge = liveTree.front();
                    Land[i][j].push(treeAge);  // O(logn)
                    if(treeAge%5 == 0) fives[i][j]++; 
                    liveTree.pop();
                }
                // 여름: 죽은 나무들 양분으로 추가, 겨울에 뿌릴 영양소도 여기서 뿌림 어차피 종속성 없음
                nut[i][j] = nut[i][j] + A[i][j] + totalDeadTreeNut;
            }
        }
        // 가을
        for(int i=1; i<=N; i++)
        {
            for(int j=1; j<=N; j++)
            {
                while(fives[i][j] > 0)
                {
                    newTree(i-1,j-1);
                    newTree(i-1,j);
                    newTree(i-1,j+1);
                    newTree(i,j-1);
                    newTree(i,j+1);
                    newTree(i+1,j-1);
                    newTree(i+1,j);
                    newTree(i+1,j+1);
                    fives[i][j]--;
                }
            }
        }
    }

    int answer = 0;
    for(int i=1; i<=N; i++)
    {
        for(int j=1; j<=N; j++)
        {
            answer += Land[i][j].size();
        }
    }
    cout << answer;
}