#include <iostream>
#include <vector>
using namespace std;
const int INF = 20000000;

// 入力された整数の中で一番小さい和を線形探索で見つける
// ただし、整数 K 以上のものの中から見つけることとする
int main(){
    int N, K;
    cin >> N >> K;
    vector<int> a(N), b(N);
    for(int i=0; i<N; ++i) cin >> a[i];
    for(int i=0; i<N; ++i) cin >> b[i];

    // Linear research method
    int min_value = INF;
    for(int i=0; i<N; ++i){
        for(int j=0; j<N; ++j){
            // K 未満は捨てる
            if (a[i]+b[j] < K) continue;

            // これまでで最小の和を更新する
            if (a[i]+b[j] < min_value) min_value = a[i]+b[j];
        }
    }

    cout << min_value << endl;
}