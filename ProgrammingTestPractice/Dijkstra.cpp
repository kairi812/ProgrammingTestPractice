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

    // Dijkstra Method
    vector<bool> used(N, false);
    vector<long long> dist(N, INF);
    dist[s] = 0;
    for (int iter=0; iter<N; ++iter) {
        long long min_dist = INF;
        int min_v = -1;

        for (int v=0; v<N; ++v) {
            if (!used[v] && dist[v] < min_dist) {
                min_dist = dist[v];
                min_v = v;
            }
        }

        if (min_v == -1) break;

        // min_v を始点とした各辺を緩和
        for (auto e : G[min_v]) {
            chmin(dist[e.to], dist[min_v]+e.w);
        }
        used[min_v] = true;
    }

    // 結果出力
    for (int v=0; v<N; ++v) {
        if (dist[v]<INF) cout << dist[v] << endl;
        else cout << "INF" << endl; 
    }
}