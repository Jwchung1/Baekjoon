// 브루트포스 문제. max_sum = 0으로 초기화해서 틀렸었음. 음수도 나올수있기 때문에 , INT32_MIN으로 초기화 해야함.

#include <iostream>
#include <stack>

using namespace std;

int N;
int numbers[12];
int operater[4]; // 0: + , 1: -, 2: *, 3: /
int max_sum = INT32_MIN;
int min_sum = INT32_MAX;

void DFS(int current_sum, int current_idx, int add, int sub, int mul, int div)
{   
    if(add > 0)
    {  
        DFS(current_sum + numbers[current_idx], current_idx + 1, add-1, sub, mul, div);
    }
    if(sub > 0)
    {
        DFS(current_sum - numbers[current_idx], current_idx + 1, add, sub-1, mul, div);
    }
    if(mul > 0)
    {
        DFS(current_sum * numbers[current_idx], current_idx + 1, add, sub, mul-1, div);
    }
    if(div > 0)
    {
        DFS(current_sum / numbers[current_idx], current_idx + 1, add, sub, mul, div-1);
    }

    if(current_idx == N)
    {
        max_sum = max(current_sum, max_sum);
        min_sum = min(current_sum, min_sum);
        return;
    }
}

int main()
{
    cin >> N;
    for(int i=0; i<N; i++)
    {
        cin >> numbers[i];
    }
    for(int i=0; i<4; i++)
    {
        cin >> operater[i];
    }

    DFS(numbers[0], 1, operater[0], operater[1], operater[2], operater[3]);
    cout << max_sum << "\n";
    cout << min_sum;
}