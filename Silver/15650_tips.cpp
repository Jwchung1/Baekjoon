// 1. 함수에 객체를 전달할떄, 참조로 전달하지 않으면 매번 함수가 불릴 때마다 복사본이 생긴다. 참조로 전달해서 비용을 절감하자.
// 2. vector<vector<int>>에 벡터가 push_back될때는 벡터의 복사본을 만들고 그것을 push_back하는 것. (깊은 복사)
// 2-1. 이 경우 복사 비용을 줄이고 싶으면 move semantics를 이용하여 복사하지 않고 원본 데이터를 그대로 옮길 수 있다. 이때 해당 벡터는 seqs에 귀속된다.
// 2-2. 이 문제에서는 인자를 vector<int>& v 로 참조로 넘기는 것과, move(v)를 같이 사용하면, 사용해야 하는 벡터가 사라져 버려서 오류가 생긴다.
//      참조로 인한 전달이기에 하나의 벡터만 가지고 조작하면 seqs에 담고 있었기 때문에 이 하나가 move로 들어가 버리면 더 이상 조작할 수 없는 것.
//      따라서 참조에 의한 전달, 혹은 move 둘 중 하나만 사용해야 한다. 복사 한번씩은 불가피함.
// 3. 깊은 복사: 객체의 모든 멤버가 복사됨. 새로이 메모리를 동적할당 받음. 
//    얕은 복사: 메모리를 동적할당 받지 않고 참조자만 복사해서 같은 공간을 가리키게함. 이러면 다른 객체에서 해당 메모리 공간을 조작하면, 복사된 객체에서도 변경됨.
#include <iostream>
#include <vector>
using namespace std;
int N, M;
vector<vector<int>> seqs;
void MakeSeq(vector<int> v, int find_start)
{
    if(v.size() == M){
        seqs.push_back(move(v));
        return;
    }
    for(int i=find_start; i<=N; i++)
    {
        v.push_back(i);
        MakeSeq(v, i+1);
        v.pop_back();
    }
}
int main()
{
    cin >> N >> M;
    vector<int> tmp;
    MakeSeq(tmp, 1);
    for(auto s:seqs)
    {
        for(auto i:s){
            cout << i << " ";
        }
        cout << "\n";
    }
}