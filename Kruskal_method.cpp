#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

using Edge = pair<int, pair<int, int>>;

struct UnionFind {
    vector<int> par, siz;
    // 初期化
    UnionFind(int n) : par(n, -1), siz(n, 1) { }
    // 根の求解
    int root(int x) {
        if (par[x] == -1) return x; // xが根の場合はxを返す
        else return par[x] = root(par[x]);
    }
    // 根の一致確認
    bool issame (int x, int y) {
        return root(x) == root(y);
    }
    // xを含むグループとyを含むグループとを併合
    bool unite (int x, int y) {
        // 根まで移動
        x = root(x); y = root(y);
        // すでに同じグループの時は何もしない
        if (x==y) return false;
        // y側のサイズを小さくする
        if (siz[x] < siz[y]) swap(x, y);
        // yをxの子とする
        par[y] = x;
        siz[x] += siz[y];
        return true;
    }
    // xを含むグループのサイズ
    int size (int x) {
        return siz[root(x)];
    }
};

int main() {
    // 頂点と辺の数
    int N, M; cin >> N >> M;
    // 辺集合
    vector<Edge> edges(M);
    for (int i=0; i<N; ++i) {
        // 新たな辺 (u, v) と重み w
        int u, v, w;
        cin >> u >> v >> w;
        edges[i] = Edge(w, make_pair(u, v));
    }

    // 各辺を辺の重みが小さい順にソート
    sort(edges.begin(), edges.end());

    // クラスカル法
    long long res = 0;
    UnionFind uf(N);
    for (int i=0; i<M; ++i) {
        int w = edges[i].first;
        int u = edges[i].second.first;
        int v = edges[i].second.second;

        // 辺 (u, v) の追加によってサイクルが形成されるときは追加しない
        if (uf.issame(u, v)) continue;

        res += w;
        uf.unite(u, v);
    }
    cout << res << endl;
}