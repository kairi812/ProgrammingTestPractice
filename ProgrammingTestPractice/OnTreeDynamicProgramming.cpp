#include <iostream>
#include <vector>
using namespace std;
using Graph = vector<vector<int>>;

// 深さ優先探索
vector<int> depth;
vector<int> subtree_size;

void dfs(const Graph &G, int v, int p = -1, int d = 0) {
    depth[v] = d;

    for (auto c : G[v]) {
        if (c==p) continue; // 探索が親方向へ逆流するのを防いでいる
        dfs(G, c, v, d+1);
    }

    // 帰りがけに部分木のサイズを求める
    subtree_size[v] = 1;
    for (auto c : G[v]) {
        if (c==p) continue;

        // 子頂点を根とする部分木のサイズを加算する
        subtree_size[v] += subtree_size[c];
    }
}

int main() {
    int N; cin >> N;
    
    // グラフ入力受取
    Graph G(N);

    for (int i=0; i<N-1; ++i) {
        int a, b; cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    // 探索
    int root = 0;
    depth.assign(N, 0); // 仮に頂点0を根とする
    subtree_size.assign(N, 0);
    dfs(G, root);

    for (int v=0; v<N; ++v) {
        cout << v << ": depth = " << depth[v]
        << ", subtree_size = " << subtree_size[v] << endl;
    }
}