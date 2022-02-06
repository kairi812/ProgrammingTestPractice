#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define INF 20000000000

// テンプレート関数
// 緩和処理を実現するための関数
template<class T>void chmin(T& a, T b){
    if(a > b) a = b;
}

int main(){
    int N; cin >> N;
    vector<int> h(N);
    for(int i=0; i<N; ++i) cin >> h[i];

    vector<long long> dp(N, INF);

    dp[0] = 0;
    for(int i=1; i<N; ++i){
        chmin(dp[i], dp[i-1] + abs(h[i] - h[i-1]));
        if (i > 1) chmin(dp[i], dp[i-2] + abs(h[i] - h[i-2]));
        // if (i==1) dp[i] = abs(h[i] - h[i-1]);
        // else dp[i] = min(dp[i-1] + abs(h[i]-h[i-1]), 
        //                  dp[i-2] + abs(h[i]-h[i-2]));
    }

    cout << dp[N-1] << endl;
}