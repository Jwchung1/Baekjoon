#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
int A[101][101];
int r,c,k;
int rowNum = 3;
int colNum = 3;
struct FreqNum{
    bool operator()(pair<int,int> p1, pair<int,int> p2) // <수, 빈도>
    {
        if(p1.second == p2.second) return p1.first < p2.first;
        else return p1.second < p2.second;
    }
};

void SortRow(int row)
{
    map<int,int> m; // <수, 빈도>
    for(int i=1; i<=colNum; i++)
    {
        if(A[row][i] == 0) continue;
        if(m[A[row][i]]) m[A[row][i]]++;
        else m[A[row][i]] = 1;
    }
    vector<pair<int,int>> tmpV;
    for(auto it=m.begin(); it!=m.end(); it++)
    {
        int number = it->first;
        int frequency = it->second;
        tmpV.push_back({number, frequency});
    }
    // tmpV 정렬
    sort(tmpV.begin(), tmpV.end(), FreqNum());
    // A배열에 수,빈도로 담기
    int arrayPos = 1;
    for(int i=0; i<tmpV.size(); i++)
    {
        A[row][arrayPos++] = tmpV[i].first;
        A[row][arrayPos++] = tmpV[i].second;
    }
    for(int i=arrayPos; i<=colNum; i++) A[row][i] = 0;
    colNum = max(colNum, arrayPos-1);
}

void SortCol(int col)
{
    map<int,int> m; // <수, 빈도>
    for(int i=1; i<=rowNum; i++)
    {
        if(A[i][col] == 0) continue;
        if(m[A[i][col]]) m[A[i][col]]++;
        else m[A[i][col]] = 1;
    }
    vector<pair<int,int>> tmpV;
    for(auto it=m.begin(); it!=m.end(); it++)
    {
        int number = it->first;
        int frequency = it->second;
        tmpV.push_back({number, frequency});
    }
    // tmpV 정렬
    sort(tmpV.begin(), tmpV.end(), FreqNum());
    // A배열에 수,빈도로 담기
    int arrayPos = 1;
    for(int i=0; i<tmpV.size(); i++)
    {
        A[arrayPos++][col] = tmpV[i].first;
        A[arrayPos++][col] = tmpV[i].second;
    }
    for(int i=arrayPos; i<=rowNum; i++) A[i][col] = 0;
    rowNum = max(rowNum, arrayPos-1);
}

void OpR()
{
    for(int i=1; i<=rowNum; i++)
    {
        SortRow(i);
    }
}

void OpC()
{
    for(int i=1; i<=colNum; i++)
    {
        SortCol(i);
    }
}

void debug()
{
    for(int i=1; i<=rowNum; i++)
    {
        for(int j=1; j<=colNum; j++)
        {
            cout << A[i][j] << " ";
        }
        cout << "\n";
    }
}

int main()
{
    
    cin >> r >> c >> k;
    for(int i=1; i<=3; i++)
    {
        for(int j=1; j<=3; j++)
        {
            cin >> A[i][j];
        }
    }
    int answer = -1;
    
    for(int t=0; t<=100; t++) // t < 100 으로 등호 없이 해서 74프로 오답났었음.
    {
        // cout << "t="<< t << "\n";
        // debug();
        if(A[r][c] == k){
            answer = t;
            break;
        }
        
        if(rowNum >= colNum)
        {
            OpR();
        }
        else
        {
            OpC();
        }
    }
    cout << answer;
}