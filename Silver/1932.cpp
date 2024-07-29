// DP 문제

#include <iostream>

using namespace std;

int n;
int triangle[501][501] = {0,};
int max_triangle[501][501] = {0,};

int main()
{
    cin >> n;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<i+1; j++)
        {
            cin >> triangle[i][j];
        }
    }

    for(int i=n-1; i>=0; i--)
    {
        for(int j=0; j<i+1; j++)
        {
            int val1 = max_triangle[i+1][j] + triangle[i][j];
            int val2 = max_triangle[i+1][j+1] + triangle[i][j];
            max_triangle[i][j] = max(val1, val2);
        }
    }

    cout << max_triangle[0][0];
}
