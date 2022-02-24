#include <iostream>
#include <vector>
using namespace std;

struct Graph{
    struct Edge {
        // rev : 逆辺 (to, from) が G[to] の中で何番目の要素か
        // cap : 辺 (to, from) の容量
        int rev, from, to, cap;
        Edge(int r, int f, int t, int c) :
            rev(r), from(f), to(t), cap(c) {}
    };

    // 隣接リスト
    vector<vector<Edge>> list;

    // N : 頂点数
    Graph(int N = 0) : list(N) { }

    // グラフの頂点数取得
    size_t size() {
        return list.size();
    }

    vector<Edge> &operator [] (int i) {
        return list[i];
    }

    // 辺 e = (u, v) の逆辺 (v, u) を取得する
    Edge& redge(const Edge &e) {
        return list[e.to][e.rev];
    }

    // 辺 e = (u, v) に流量 f のフローを流す
    void run_flow(Edge &e, int f) {
        e.cap -= f;
        redge(e).cap += f;
    }

    void addedge(int from, int to, int cap) {
        int fromrev = (int)list[from].size();
        int torev = (int)list[to].size();
        list[from].push_back(Edge(torev, from, to, cap));
        list[to].push_back(Edge(fromrev, to, from, 0));
    }
};

struct FordFulkerson {
    static const int INF = 1 << 30;
    vector<int> seen;

    FordFulkerson() { }

    int fodfs(Graph &G, int v, int t, int f) {
        if (v==t) return f;
        // 深さ優先探索
        seen[v] = true;
        for (auto &e : G[v]) {
            if (seen[e.to]) continue;
            // s-t パスを探す
            int flow = fodfs(G, e.to, t, min(f, e.cap));

            if (flow==0) continue;

            G.run_flow(e, flow);

            return flow;
        }

        return 0;
    }

    int solve(Graph &G, int s, int t) {
        int res = 0;

        while (true) {
            seen.assign((int)G.size(), 0);
            int flow = fodfs(G, s, t, INF);

            if (flow==0) return res;

            res += flow;
        }
        return 0;
    }
};

int main() {
    // N : 頂点数、M : 辺数
    int N, M; cin >> N >> M;
    Graph G(N);
    for (int i=0; i<N; ++i) {
        int u, v, c;
        cin >> u >> v >> c;

        G.addedge(u, v, c);
    }

    FordFulkerson ff;
    int s = 0, t = N -1;
    cout << ff.solve(G, s, t) << endl;
}