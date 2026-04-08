// Bài 3: CHONCAY — DFS (BFS order) + Tree DP
#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream in("CHONCAY.INP");
    ofstream out("CHONCAY.OUT");

    int n;
    in >> n;

    vector<long long> w(n + 1);
    for (int i = 1; i <= n; i++) in >> w[i];

    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        in >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // BFS to get traversal order + parent
    vector<int> order, par(n + 1, 0);
    vector<bool> visited(n + 1, false);
    queue<int> q;
    q.push(1);
    visited[1] = true;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        order.push_back(u);
        for (int i = 0; i < (int)adj[u].size(); i++) {
            int v = adj[u][i];
            if (!visited[v]) {
                visited[v] = true;
                par[v] = u;
                q.push(v);
            }
        }
    }

    // Process in reverse BFS order (leaves first)
    vector<long long> dp0(n + 1, 0), dp1(n + 1);
    for (int i = 1; i <= n; i++) dp1[i] = w[i];

    for (int i = (int)order.size() - 1; i >= 0; i--) {
        int u = order[i];
        for (int j = 0; j < (int)adj[u].size(); j++) {
            int v = adj[u][j];
            if (v == par[u]) continue;
            dp0[u] += max(dp0[v], dp1[v]);
            dp1[u] += dp0[v];
        }
    }

    out << max(dp0[1], dp1[1]);

    in.close();
    out.close();
    return 0;
}
