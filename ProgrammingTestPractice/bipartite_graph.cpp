#include <iostream>
#include <vector>
using namespace std;
using Graph = vector<vector<int>>;

// 深さ優先探索
vector<bool> color;
bool dfs(const Graph &G, int v, int cur = 0) {
    color[v] = cur;

    for (auto next_v : G[v]) {
        if (color[next_v] != -1) {
            if (color[next_v] == cur) return false;

            continue;
        }
        if (!dfs(G, next_v, 1-cur)) return false;
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
    color.assign(N, -1); // 初期状態においては全て未探索
    bool is_bipartite = true;
    for (int v=0; v<N; ++v) {
        if (color[v] != -1) continue; // すでに訪問済みは探索しない
        if (!dfs(G, v)) is_bipartite = false;
    }

    if (is_bipartite) cout << "Yes" << endl;
    else cout << "No" << endl;
}