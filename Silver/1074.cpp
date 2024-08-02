// 큰 조각에서 작은 조각으로 범위를 줄여가면서 재귀하는 풀이.
// 항상 배열이 4등분되므로, 어느 등분에 목적지가 해당되는지 좁혀나간다.
// 이때, r과 c 역시 바꿔줘야하는데, 조각이 작아지며, 같은 지점을 나타내는 점이 표현이 달라지기 때문.
// 4x4 배열에서 (3,1)은 3사분면 내부에서 (1,1) 이므로 작아지면서 r,c를 갱신해줘야한다.

#include <iostream>
#include <math.h>
using namespace std;

int N, r, c;

void rec(int row, int column)
{

}

int main()
{
    cin >> N >> r >> c;
    int num = 0;
    while(N > 0)
    {
        int edge = pow(2,N-1);
        int offset = pow(edge, 2);
        if(c < edge)
        {
            if(r < edge)
            {
                // 1사분면
                //cout << "1dim\n";
                num += 0;
            }
            else
            {
                // 3사분면
                //cout << "3dim\n";
                num += offset * 2;
                r -= edge;
            }
        }
        else
        {
            if(r < edge)
            {
                // 2사분면
                //cout << "2dim\n";
                num += offset;
                c -= edge;
            }
            else
            {
                // 4사분면
                //cout << "4dim\n";
                num += offset * 3;
                r -= edge;
                c -= edge;
            }
        }
        N--;
    }
    cout << num;
}