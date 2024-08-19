#include <iostream>
#include <queue>
using namespace std;
int visited[200001];
int main()
{
    int N, K;
    cin >> N >> K;
    queue<pair<int,int>> q;
    q.push({N,0});
    for(int i=0; i<200000; i++)
    {
        visited[i] = INT32_MAX;
    }
    visited[N] = 0;
    
    while(!q.empty())
    {
        int cur = q.front().first;
        int time = q.front().second;
        //cout << cur << "," << time << "\n";
        q.pop();
        if(cur < K){
            if(visited[cur*2] > time) {
                visited[cur*2] = time;
                q.push({cur*2, time});
            }
            if(visited[cur-1] > time+1) {
                visited[cur-1] = time+1;
                q.push({cur-1, time+1});
            }
            if(visited[cur+1] > time+1) {
                visited[cur+1] = time+1;
                q.push({cur+1, time+1});
            }
        }
        else if(cur > K)
        {
            if(visited[cur-1] > time+1) {
                visited[cur-1] = time+1;
                q.push({cur-1, time+1});
            }
        }
    }
    cout << visited[K];
}