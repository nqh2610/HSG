// Bai 3: GIAMGIA — Bellman-Ford O(N*M)
#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream in("GIAMGIA.INP");
    ofstream out("GIAMGIA.OUT");

    int n, m;
    in >> n >> m;

    vector<int> eu(m), ev(m);
    vector<long long> ew(m);
    for (int i = 0; i < m; i++)
        in >> eu[i] >> ev[i] >> ew[i];

    const long long INF = 1e18;
    vector<long long> d(n + 1, INF);
    d[1] = 0;
    for (int i = 0; i < n - 1; i++) {
        bool updated = false;
        for (int j = 0; j < m; j++) {
            if (d[eu[j]] < INF && d[eu[j]] + ew[j] < d[ev[j]]) {
                d[ev[j]] = d[eu[j]] + ew[j];
                updated = true;
            }
        }
        if (!updated) break;
    }

    if (d[n] >= INF) out << -1;
    else out << d[n];

    in.close();
    out.close();
    return 0;
}
