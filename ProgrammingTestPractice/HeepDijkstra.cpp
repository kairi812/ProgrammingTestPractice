#include <iostream>
#include <vector>
#include <queue>
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

    vector<long long> dist(N, INF);
    dist[s] = 0;

    // (d[v], v)のペアを要素としたヒープ作成
    priority_queue<pair<long long, int>,
                   vector<pair<long long, int>>,
                   greater<pair<long long, int>>> que;
    que.push(make_pair(dist[s], s));

    // ダイクストラ法の反復開始
    while(!que.empty()) {
        // v : 使用済みでない頂点のうち d[v] が最小の頂点
        // d : v に対するキー値
        int v = que.top().second;
        long long d = que.top().first;
        que.pop();

        // 以下の条件は (d, v) がゴミである
        if (d>dist[v]) continue;

        // 頂点 v を始点とした各辺を緩和
        for (auto e : G[v]) {
            if (chmin(dist[e.to], dist[v]+e.w)) {
                que.push(make_pair(dist[e.to], e.to));
            }
        }
    }

    // 結果表示
    for (int v=0; v<N; ++v) {
        if (dist[v]<INF) cout << dist[v] << endl;
        else cout << "INF" << endl;
    }
}