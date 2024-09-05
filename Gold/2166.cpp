// 삼각형이면 일단 신발끈

#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
using namespace std;
vector<pair<double,double>> v;

double Cross(pair<double,double> p1, pair<double,double> p2, pair<double,double> p3)
{
    double x1 = p1.first;
    double x2 = p1.second;
    double y1 = p2.first;
    double y2 = p2.second;
    double z1 = p3.first;
    double z2 = p3.second;
    double res = x1*y2 - x2*y1 + y1*z2 - z1*y2 + z1*x2 - x1*z2;
    return res/2;
}

int main()
{
    int N;
    cin >> N;
    for(int i=0; i<N; i++)
    {   
        double x, y;
        cin >> x >> y;
        v.push_back({x,y});
    }
    double sum = 0;
    for(int i=2; i<N; i++)
    {
        sum += Cross(v[0], v[i], v[i-1]);
    }
    cout << fixed << setprecision(1) << abs(sum);
}