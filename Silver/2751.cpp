// endl -> "\n" 로 바꾸는 사소한 최적화 기법 존재 

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int N;
    cin >> N;
    int arr[1000000];
    for(int i=0; i<N; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr+N);

    for(int i=0; i<N; i++)
    {
        cout << arr[i] << "\n";
    }
}
