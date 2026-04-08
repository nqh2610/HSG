// Bài 3: CAUNOI — Binary Search Answer + BFS
#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream in("CAUNOI.INP");
    ofstream out("CAUNOI.OUT");

    int n, m;
    in >> n >> m;

    vector<vector<pair<int,int> > > adj(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v, c;
        in >> u >> v >> c;
        adj[u].push_back(make_pair(v, c));
        adj[v].push_back(make_pair(u, c));
    }

    // Binary search on answer
    int lo = 1, hi = 1000000000, ans = 0;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;

        // BFS: only use edges with capacity >= mid
        vector<bool> visited(n + 1, false);
        queue<int> q;
        q.push(1);
        visited[1] = true;
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (int j = 0; j < (int)adj[u].size(); j++) {
                int v = adj[u][j].first;
                int c = adj[u][j].second;
                if (!visited[v] && c >= mid) {
                    visited[v] = true;
                    q.push(v);
                }
            }
        }

        if (visited[n]) {
            ans = mid;
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }

    out << ans;

    in.close();
    out.close();
    return 0;
}
