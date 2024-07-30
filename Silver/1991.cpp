// 트리의 전위순회, 중위순회, 후위순회 문제. visited를 언제 호출할것인지가 관건
// 전위: visited -> left -> right
// 중위: left -> visited -> right
// 후위: left -> right -> visited

#include <iostream>
#include <stack>

using namespace std;

int N;
char tree[30][3] = {'.',}; // left, right, parent 'A'의 인덱스는 int 'A' - 'A'

void preorder()
{
    // root인 0인덱스에서 시작
    stack<int> s;
    s.push(0);
    int visited[30] = {0, };

    while(!s.empty())
    {
        int cur = s.top();
        
        if(visited[cur] != 1)
        {
            visited[cur] = 1;
            cout << (char)(cur + 'A');
        }
        
        if(tree[cur][0] != '.' && visited[tree[cur][0] - 'A'] != 1)
        {
            // left가 존재하면
            s.push(tree[cur][0] - 'A');
            // visited[tree[cur][0] - 'A'] = 1;
            // cout << tree[cur][0];
            continue;
        }
        else if(tree[cur][1] != '.' && visited[tree[cur][1] - 'A'] != 1)
        {
            // right가 존재하면
            s.push(tree[cur][1] - 'A');
            // visited[tree[cur][1] - 'A'] = 1;
            // cout << tree[cur][1];
            continue;
        }
        // 아무것도 존재 안하면
        s.pop();
    }
}

void inorder()
{
    stack<int> s;
    s.push(0);
    int visited[30] = {0, };

    while(!s.empty())
    {
        int cur = s.top();
        
        if(tree[cur][0] != '.' && visited[tree[cur][0] - 'A'] != 1)
        {
            // left가 존재하면
            s.push(tree[cur][0] - 'A');
            continue;
        }
        
        visited[cur] = 1;
        cout << (char)(cur + 'A');
        s.pop();

        if(tree[cur][1] != '.' && visited[tree[cur][1] - 'A'] != 1)
        {
            // right가 존재하면
            s.push(tree[cur][1] - 'A');
            continue;
        }
    }
}

void postorder()
{
    stack<int> s;
    s.push(0);
    int visited[30] = {0, };

    while(!s.empty())
    {
        int cur = s.top();
        
        if(tree[cur][0] != '.' && visited[tree[cur][0] - 'A'] != 1)
        {
            // left가 존재하면
            s.push(tree[cur][0] - 'A');
            continue;
        }
        else if(tree[cur][1] != '.' && visited[tree[cur][1] - 'A'] != 1)
        {
            // right가 존재하면
            s.push(tree[cur][1] - 'A');
            continue;
        }
        // 아무것도 존재 안하면
        visited[cur] = 1;
        cout << (char)(cur + 'A');
        s.pop();
    }
}

int main()
{
    cin >> N;
    for(int i=0; i<N; i++)
    {
        char self, left, right;
        cin >> self >> left >> right;
        tree[self - 'A'][0] = left;
        tree[self - 'A'][1] = right;

        if(left != '.') tree[left - 'A'][2] = self;
        if(right != '.') tree[right - 'A'][2] = self;
    }
    preorder();
    cout << "\n";
    inorder();
    cout << "\n";
    postorder();
}