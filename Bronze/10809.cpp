#include <iostream>
#include <vector>
#include <string>
using namespace std;
string s;
vector<int> v;
int main()
{
    cin >> s;
    v.resize(30,-1);
    for(int i=0; i<26; i++)
    {
        char cur = (char)(i + 'a');
        for(int j=0; j<s.size(); j++)
        {
            if(s[j] == cur)
            {
                v[i] = j;
                break;
            }
        }
    }
    for(int i=0; i<26; i++)
    {
        cout << v[i];
        if(i != v.size()-1) cout << " ";
    }
}