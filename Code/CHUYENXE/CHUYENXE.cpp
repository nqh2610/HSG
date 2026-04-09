// Bai 1: CHUYENXE — Floyd-Warshall O(N^3)
#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream in("CHUYENXE.INP");
    ofstream out("CHUYENXE.OUT");

    int n, m, q;
    in >> n >> m >> q;

    const long long INF = 1e18;
    vector<vector<long long> > d(n + 1, vector<long long>(n + 1, INF));
    for (int i = 1; i <= n; i++) d[i][i] = 0;
    for (int i = 0; i < m; i++) {
        int u, v;
        long long w;
        in >> u >> v >> w;
        d[u][v] = min(d[u][v], w);
    }

    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                if (d[i][k] < INF && d[k][j] < INF)
                    d[i][j] = min(d[i][j], d[i][k] + d[k][j]);

    for (int i = 0; i < q; i++) {
        int s, t;
        in >> s >> t;
        if (d[s][t] >= INF) out << -1;
        else out << d[s][t];
        out << "\n";
    }

    in.close();
    out.close();
    return 0;
}
