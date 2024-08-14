// Delete 최적화 (자료구조를 덱을 쓰자) O(N) -> O(1)
// v.erase는 시간복잡도 O(n). 싹 미루는 작업 필요해서.
// deque은 스택과 큐를 합친 자료구조면서, 원소에 인덱스로 접근 가능. 앞 원소 제거가 시간복잡도 O(1)
// Reverse 최적화 O(N) -> O(1)
// 매번 배열을 실제로 뒤집는 데에는 O(N) 시간 복잡도가 든다.
// 굳이 매번 뒤집지 말고, ReverseFlag만 설정해놓고, 0이면 앞에서 delete, 1이면 뒤에서 delete.
// 출력할때만 0인지 1인지 보고 순방향 출력 혹은 역방향 출력을 하면 된다.
// 그 외 틀린 이유
// 하나의 TC를 출력하고 "\n"이걸 안했음.
// 출력형식 여는괄호 닫는 괄호 문제.

#include <iostream>
#include <vector>
#include <deque>
#include <math.h>
using namespace std;

int T;
deque<int> d;
int ReverseFlag = 0; // 0이 정방향, 1이 역방향

int StringToInt(string s)
{
    int sum = 0;
    int p = 0;
    int size = s.size();
    for(int i=size-1; i>=0; i--)
    {
        sum += (int)(s[i] - '0') * pow(10, p);
        p++;
    }
    return sum;
}
void ParseArr(string arr)
{
    d.clear();
    string buf = "";
    int size = arr.size();
    for(int i=0; i<size; i++)
    {
        if(arr[i] == '[')
        {
            continue;
        }
        else if(arr[i] == ',' || (arr[i] == ']' && buf != ""))
        {
            d.push_back(StringToInt(buf));
            buf = "";
        }
        else
        {
            buf = buf + arr[i];
        }
    }
}
void ReverseArr()
{
    //뒤집기
    ReverseFlag = (ReverseFlag+1)%2;
}
void DeleteFirst()
{
    //버리기
    if(ReverseFlag == 0) d.pop_front();
    else d.pop_back();
}
void PrintArr()
{
    cout << "[";
    int size = d.size();
    if(ReverseFlag == 0)
    {
        for(int i=0; i<size; i++)
        {
            if(i==size-1)
            {
                cout << d[i];
            }
            else
            {
                cout << d[i] << ",";
            }
        } 
    }
    else
    {
        for(int i=size-1; i>=0; i--)
        {
            if(i==0)
            {
                cout << d[i];
            }
            else
            {
                cout << d[i] << ",";
            }
        } 
    }     
    cout << "]\n";
}
void Operation(string p)
{
    int size = p.size();
    for(int i=0; i<size; i++)
    {
        if(p[i] == 'R')
        {
            ReverseArr();
        }
        else
        {
            if(d.empty())
            {
                cout << "error\n";
                return;
            }
            DeleteFirst();
        }
    }
    PrintArr();
}

int main()
{
    cin >> T;
    while(T-- > 0)
    {
        string p;
        int n;
        string arr;
        cin >> p;
        cin >> n;
        cin >> arr;
        ParseArr(arr);
        ReverseFlag = 0;
        Operation(p);
    }
}