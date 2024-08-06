// ****** 솔직히 답 봐도 잘 이해 안되는 재귀 문제. 별표 세개 

#include <iostream>
#include <vector>
#include <string>
using namespace std;
int N;
void rec(int i, int j, int edge) // pos가 "*" 인지 " " 인지 재귀를 통해 확인 해당 큰 덩어리의 9타일 중 중앙 타일이면 " "출력 edge는 타일 하나의 변 길이
{
    // edge가 i보다 작거나 같아지는 순간 유의미한 나머지 결과 나옴. 한 덩어리가 edge*edge 만큼의 크기일때, 
    // 이게 몇번째 타일인지 확인하는 것. 둘다 나머지가 1이면 중앙 타일이라는 뜻.
    if((i/edge)%3 == 1 && (j/edge)%3 == 1) 
    {
        cout << " ";
    }
    else if(edge == 1) // edge가 더 이상 줄어들 수 없으면서, 위 조건 만족 안하니까 * 출력
    {
        cout << "*";
    }
    else
    {
        rec(i, j, edge/3); // edge 계속 3등분으로 깎아나가기
    }
}

int main()
{
    cin >> N;
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            rec(i, j, N);
        }
        cout << "\n";
    }
}