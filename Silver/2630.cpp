// 재귀 문제

#include <iostream>
using namespace std;
int N;
int blues = 0;
int whites = 0;
int paper[129][129];
void rec(int edge, int start_x, int start_y)
{
    bool isEnd = true;
    int pivot = paper[start_x][start_y];
    for(int i=start_x; i<start_x + edge; i++)
    {
        for(int j=start_y; j<start_y + edge; j++)
        {
            if(pivot != paper[i][j]){
                isEnd = false;
                break;
            }
        }
    }
    if(isEnd){
        if(pivot == 1) blues++;
        else whites++;
        return;
    }
    else{
        rec(edge/2, start_x, start_y);
        rec(edge/2, start_x + edge/2, start_y);
        rec(edge/2, start_x , start_y + edge/2);
        rec(edge/2, start_x + edge/2, start_y + edge/2);
    }
}
int main()
{
    cin >> N;
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            cin >> paper[i][j];
        }
    }
    rec(N, 0, 0);
    cout << whites << "\n" << blues;
}