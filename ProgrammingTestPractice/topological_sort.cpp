#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using Graph = vector<vector<int>>;

// 深さ優先探索
vector<bool> seen;
vector<int> order; // トポロジカルソート順を表す
void rec(const Graph &G, int v) {
    seen[v] = true;

    for (auto next_v : G[v]) {
        if (seen[next_v]) continue;
        rec(G, next_v);
    }

    // v-outを記録
    order.push_back(v);
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
    order.clear();
    for (int v=0; v<N; ++v) {
        if (seen[v]) continue; // すでに訪問済みは探索しない
        rec(G, v);
    }
    reverse(order.begin(), order.end()); // 逆順にする

    for (auto v : order) cout << v << " -> ";
    cout << endl;
}