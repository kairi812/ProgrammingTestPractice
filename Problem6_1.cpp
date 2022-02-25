#include <iostream>
#include <vector>
using namespace std;

template<class T> void chmax(T&a, T b) {
    if (a < b) a = b;
}

int main() {
    int N; cin >> N;

    vector<vector<long long>> a(N, vector<long long>(3));
    for (int i=0; i<N; ++i) {
        for (int j=0; j<3; ++j){
            cin >> a[i][j];
        }
    }
    // DP Table
    vector<vector<long long>> dp(N+1, vector<long long>(3, 0));

    // 6通りずつ考える
    // dp[i][0] から dp[i+1][1]
    // dp[i][0] から dp[i+1][2]
    // dp[i][1] から dp[i+1][0]
    // dp[i][1] から dp[i+1][2]
    // dp[i][2] から dp[i+1][0]
    // dp[i][2] から dp[i+1][1]
    // j と k を定義し、それぞれで max となるものを算出
    for (int i=0; i<N; ++i) {
        for (int j=0; j<3; ++j) {
            for (int k=0; k<3; ++k){
                if (j==k) continue;
                chmax(dp[i+1][k], dp[i][j]+a[i][k]);
            }
        }
    }
    // Answer
    long long res = 0;
    for (int j=0; j<3; ++j) chmax(res, dp[N][j]);
    cout << res << endl;
}