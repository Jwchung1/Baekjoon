// 삼각형이면 일단 신발끈

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<pair<int,int>> v;
// (x1,y1,z1)
// (x2,y2,z2) = x1y2 - x2y1 + y1z2 - z1y2 + z1x2 - x1z2
int Cross(pair<int,int> p1, pair<int,int> p2, pair<int,int> p3)
{
    int x1 = p1.first;
    int x2 = p1.second;
    int y1 = p2.first;
    int y2 = p2.second;
    int z1 = p3.first;
    int z2 = p3.second;
    int res = x1*y2 - x2*y1 + y1*z2 - z1*y2 + z1*x2 - x1*z2;
    if(res == 0) return 0;
    else if(res > 0) return 1;
    else return -1;
}

int main()
{
    for(int i=0; i<3; i++)
    {
        int x, y;
        cin >> x >> y;
        v.push_back({x,y});
    }
    cout << Cross(v[0], v[1], v[2]);
    
}