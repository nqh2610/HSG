#include <bits/stdc++.h>
using namespace std;

int n, m;
int cha[100001], sz[100001];

int Find(int x) {
    if (cha[x] != x) cha[x] = Find(cha[x]);
    return cha[x];
}

void Union(int a, int b) {
    a = Find(a);
    b = Find(b);
    if (a == b) return;
    if (sz[a] < sz[b]) swap(a, b);
    cha[b] = a;
    sz[a] += sz[b];
}

int main() {
    ifstream in("VUOTCAU.INP");
    ofstream out("VUOTCAU.OUT");

    in >> n >> m;

    vector<pair<int, pair<int, int>>> edges(m);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        in >> u >> v >> w;
        edges[i] = make_pair(w, make_pair(u, v));
    }

    // Sap xep canh giam dan theo trong so
    sort(edges.begin(), edges.end(), greater<pair<int, pair<int, int>>>());

    for (int i = 1; i <= n; i++) {
        cha[i] = i;
        sz[i] = 1;
    }

    for (int i = 0; i < m; i++) {
        int w = edges[i].first;
        int u = edges[i].second.first;
        int v = edges[i].second.second;
        Union(u, v);
        if (Find(1) == Find(n)) {
            out << w;
            in.close();
            out.close();
            return 0;
        }
    }

    out << 0;

    in.close();
    out.close();
    return 0;
}
