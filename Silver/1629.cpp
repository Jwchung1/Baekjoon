// 분할 정복으로 연산횟수를 줄이는게 포인트였던 문제. 
// 중복되는 연산을 저장해서 연산횟수를 줄이는 방식이다.
// 구해야하는 곱셈을 두개로 분리해서 한쪽만 계산한 후, 제곱할 때 그 구한 값을 저장해놓고 바로 곱하는 식으로 연산을 줄인다.
// 처음엔 tmp에 저장 안하고 재귀를 두번 불러서 했는데, 왠지 모르게 백준에서 통과가 됐다.
// 백준 컴파일러가 알아서 최적화를 해주는지 시간도 0ms로 저장했을 때와 똑같이 떴다.

#include <iostream>

using namespace std;

int A,B,C;
long long rec(long long b)
{
    if(b == 0) return 1;
    long long tmp = rec(b/2)%C;
    tmp = tmp * tmp % C;
    // b가 홀수면
    if(b % 2 == 1)
    {
        return tmp * A % C;
    }
    // b가 짝수면
    else
    {
        return tmp;
    }
}

int main()
{
    cin >> A >> B >> C;
    cout << rec(B)%C;
}