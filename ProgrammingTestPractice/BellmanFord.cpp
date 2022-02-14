#include <iostream>
#include <vector>
using namespace std;

const long long INF = 1LL << 60;

// 辺を表す型
struct Edge {
    int to;
    long long w;
    Edge(int to, long long w) : to(to), w(w) {}
};

// 重み付きグラフ
using Graph = vector<vector<Edge>>;

// 緩和を実施する関数
template<class T> bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    else return false;
}

int main() {
    // 頂点数、変数、始点
    int N, M, s;
    cin >> N >> M >> s;

    Graph G(N);
    for (int i=0; i<M; ++i) {
        int a, b, w;
        cin >> a >> b >> w;
        G[a].push_back(Edge(b, w));
    }

    // Bellman-Ford Method
    bool exist_negative_cycle = false; // 負閉路をもつかどうか
    vector<long long> dist(N, INF);
    dist[s] = 0; // 始点は 0
    for (int iter=0; iter<N; ++iter) {
        bool update = false; // 更新フラグ
        for (int v=0; v<N; ++v) {
            // INF のときは緩和をしない
            if (dist[v] == INF) continue;

            for (auto e : G[v]) {
                // 緩和処理実行
                if (chmin(dist[e.to], dist[v]+e.w)){
                    update = true;
                }
            }
        }
        // 更新されなければ最短経路が算出されている
        if (!update) break;

        // N 回目の反復で更新が行なわれている場合、負閉路をもつ
        if (iter == N-1 && update) exist_negative_cycle = true;
    }

    // 結果出力
    if (exist_negative_cycle) cout << "NEGATIVE CYCLE" << endl;
    else {
        for (int v=0; v<N; ++N) {
            if (dist[v] < INF) cout << dist[v] << endl;
            else cout << "INF" << endl;
        }
    }
}