#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100005;
vector<pair<int,int>> adj[MAXN];
long long dp[MAXN];
long long ans;
void dfs(int u, int parent) {
    dp[u] = 0;
    for(int i = 0; i < (int)adj[u].size(); i++) {
        int v = adj[u][i].first;
        int w = adj[u][i].second;
        if(v == parent) continue;
        dfs(v, u);
        ans = max(ans, dp[u] + dp[v] + w);
        dp[u] = max(dp[u], dp[v] + w);
    }
}
int main() {
    ifstream in("DUONGCAY.INP");
    ofstream out("DUONGCAY.OUT");
    int n;
    in >> n;
    for(int i = 0; i < n - 1; i++) {
        int u, v, w;
        in >> u >> v >> w;
        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }
    ans = 0;
    dfs(1, 0);
    out << ans;
    in.close(); out.close(); return 0;
}
