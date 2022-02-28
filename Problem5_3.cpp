#include <iostream>
#include <vector>
using namespace std;

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
            if (!dp[i][j]) continue;
            dp[i+1][j] = true;
            if (j+a[i] <= W) dp[i+1][j+a[i]] = true;
        }
    }

    int res = 0;
    for (int j=0; j<=W; ++j) {
        if (dp[N][j]) ++res;
    }

    cout << res << endl;

}