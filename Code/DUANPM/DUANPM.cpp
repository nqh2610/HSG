// Bai 3: DUANPM — Topo Sort + DP on DAG O(N+M)
#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream in("DUANPM.INP");
    ofstream out("DUANPM.OUT");

    int n, m;
    in >> n >> m;
    vector<int> d(n + 1), indeg(n + 1, 0);
    vector<vector<int> > adj(n + 1);
    for (int i = 1; i <= n; i++) in >> d[i];
    for (int i = 0; i < m; i++) {
        int u, v;
        in >> u >> v;
        adj[u].push_back(v);
        indeg[v]++;
    }

    vector<long long> dp(n + 1, 0);
    queue<int> q;
    for (int i = 1; i <= n; i++)
        if (indeg[i] == 0) {
            q.push(i);
            dp[i] = d[i];
        }

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int j = 0; j < (int)adj[u].size(); j++) {
            int v = adj[u][j];
            dp[v] = max(dp[v], dp[u]);
            if (--indeg[v] == 0) {
                dp[v] += d[v];
                q.push(v);
            }
        }
    }

    long long ans = 0;
    for (int i = 1; i <= n; i++) ans = max(ans, dp[i]);
    out << ans;

    in.close();
    out.close();
    return 0;
}
