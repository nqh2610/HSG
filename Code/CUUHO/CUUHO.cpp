// Bai 2: CUUHO — Re-rooting DP on Tree O(N)
#include <bits/stdc++.h>
using namespace std;

int n;
vector<pair<int, long long> > adj[100001];
long long sz[100001], dist_arr[100001], dp[100001];

void dfs1(int u, int p, long long d) {
    sz[u] = 1;
    dist_arr[u] = d;
    for (int i = 0; i < (int)adj[u].size(); i++) {
        int v = adj[u][i].first;
        long long w = adj[u][i].second;
        if (v != p) {
            dfs1(v, u, d + w);
            sz[u] += sz[v];
        }
    }
}

void dfs2(int u, int p) {
    for (int i = 0; i < (int)adj[u].size(); i++) {
        int v = adj[u][i].first;
        long long w = adj[u][i].second;
        if (v != p) {
            dp[v] = dp[u] + (n - 2 * sz[v]) * w;
            dfs2(v, u);
        }
    }
}

int main() {
    ifstream in("CUUHO.INP");
    ofstream out("CUUHO.OUT");

    in >> n;
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        long long w;
        in >> u >> v >> w;
        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }

    dfs1(1, 0, 0);
    dp[1] = 0;
    for (int i = 1; i <= n; i++) dp[1] += dist_arr[i];
    dfs2(1, 0);

    long long ans = dp[1];
    for (int i = 2; i <= n; i++) ans = min(ans, dp[i]);
    out << ans;

    in.close();
    out.close();
    return 0;
}
