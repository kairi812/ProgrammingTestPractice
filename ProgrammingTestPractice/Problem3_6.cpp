#include <iostream>
#include <vector>
#define INF 20000000;
using namespace std;

int main(){
    int K, N; cin >> K >> N;

    int cnt = 0;
    // O(N^2)の解法
    for(int x=0; x<=K; ++x){
        for(int y=0; y<=K; ++y){
            int z = N - x - y;
            if (0 <= z && z <= K) ++cnt;
        }
    }
    cout << cnt << endl;
}