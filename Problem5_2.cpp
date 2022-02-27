#include <iostream>
#include <vector>
using namespace std;

template<class T> void chmin(T&a, T b) {

};

int main() {
    int N, W; cin >> N >> W;
    vector<int> a(N);
    for (int i=0; i<N; ++i) cin >> a[i];
    // DP
    // 初期化
    vector<vector<bool>> dp(N+1, vector<bool>(W+1, false));
    dp[0][0] = true;
    // 更新
    for (int i=0; i<N; ++i){
        for (int j; j<=W; ++ j){
            // a[i]を選ばない場合
            if (dp[i][j]) dp[i+1][j] = true;
            // a[i]を選ぶ場合
            if (j >= a[i] && dp[i][j-a[i]]) dp[i+1][j] = true;
        }
    }

    if (dp[N][W]) cout << "Yes" << endl;
    else cout << "No" << endl;
}