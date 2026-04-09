// Bai 2: CHIADOI — Bipartite BFS O(N+M)
#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream in("CHIADOI.INP");
    ofstream out("CHIADOI.OUT");

    int n, m;
    in >> n >> m;
    vector<vector<int> > adj(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v;
        in >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> color(n + 1, -1);
    bool ok = true;
    for (int s = 1; s <= n && ok; s++) {
        if (color[s] != -1) continue;
        queue<int> q;
        color[s] = 1;
        q.push(s);
        while (!q.empty() && ok) {
            int u = q.front();
            q.pop();
            for (int j = 0; j < (int)adj[u].size(); j++) {
                int v = adj[u][j];
                if (color[v] == -1) {
                    color[v] = 3 - color[u];
                    q.push(v);
                } else if (color[v] == color[u]) {
                    ok = false;
                }
            }
        }
    }

    if (!ok) {
        out << "NO";
    } else {
        out << "YES\n";
        for (int i = 1; i <= n; i++) {
            if (i > 1) out << " ";
            out << color[i];
        }
    }

    in.close();
    out.close();
    return 0;
}
