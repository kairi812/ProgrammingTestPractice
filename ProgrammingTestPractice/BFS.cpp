#include <iostream>
#include <vector>
#include <queue>
using namespace std;
using Graph = vector<vector<int>>;

vector<int> BFS(const Graph &G, int s) {
    int N = (int)G.size();
    vector<int> dist(N, -1);
    queue<int> que;

    dist[0] = 0; // 頂点0を初期頂点にする
    que.push(0);

    // キューが空になるまで探索
    while(!que.empty()) {
        int v = que.front();
        que.pop();

        // vから辿れる頂点全てに対して調査
        for (int x : G[v]) {
            if (dist[x] != -1) continue;

            // 新たな頂点について距離情報を更新してキューに挿入
            dist[x] = dist[v] + 1;
            que.push(x);
        }
    }
    return dist;
}

int main() {
    int N, M; cin >> N >> M;

    // グラフ入力受け取り（無向グラフを想定）
    Graph G(N);
    for (int i=0; i<M; ++i) {
        int a, b; cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    // 頂点0を視点としたBFS
    vector<int> dist = BFS(G, 0);

    for (int v=0; v<N; ++v) cout << v << ": " << dist[v] << endl;
}