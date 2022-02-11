#include <iostream>
#include <vector>
using namespace std;
using Graph = vector<vector<int>>;

// 深さ優先探索
vector<bool> seen;
void dfs(const Graph &G, int v) {
    seen[v] = true;

    for (auto next_v : G[v]) {
        if (seen[next_v]) continue;
        dfs(G, next_v);
    }
}

int main() {
    int N, M; cin >> N >> M;
    
    // グラフ入力受取
    Graph G(N);

    for (int i=0; i<M; ++i) {
        int a, b; cin >> a >> b;
        G[a].push_back(b);
    }

    // 探索
    seen.assign(N, false); // 初期状態においては全て未探索
    for (int v=0; v<N; ++v) {
        if (seen[v]) continue; // すでに訪問済みは探索しない
        dfs(G, v);
    }
}