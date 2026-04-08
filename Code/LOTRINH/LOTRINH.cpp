// Bài 3: LOTRINH — Topo Sort + DP on DAG O(N+M)
#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream in("LOTRINH.INP");
    ofstream out("LOTRINH.OUT");

    int n, m;
    in >> n >> m;

    vector<vector<pair<int,int>>> ke(n + 1);
    vector<int> indeg(n + 1, 0);

    for (int i = 0; i < m; i++) {
        int u, v, w;
        in >> u >> v >> w;
        ke[u].push_back(make_pair(v, w));
        indeg[v]++;
    }

    // Topological sort (Kahn's BFS)
    queue<int> q;
    for (int i = 1; i <= n; i++)
        if (indeg[i] == 0) q.push(i);

    vector<int> topo;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        topo.push_back(u);
        for (int i = 0; i < (int)ke[u].size(); i++) {
            int v = ke[u][i].first;
            if (--indeg[v] == 0) q.push(v);
        }
    }

    // DP: dp[v] = longest path from 1 to v
    vector<long long> dp(n + 1, -1);
    dp[1] = 0;

    for (int i = 0; i < (int)topo.size(); i++) {
        int u = topo[i];
        if (dp[u] == -1) continue;
        for (int j = 0; j < (int)ke[u].size(); j++) {
            int v = ke[u][j].first;
            int w = ke[u][j].second;
            dp[v] = max(dp[v], dp[u] + w);
        }
    }

    out << dp[n];

    in.close();
    out.close();
    return 0;
}
