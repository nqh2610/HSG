// Bai 3: CAPNUOC — Pre-merge sources + Kruskal MST O(M log M)
#include <bits/stdc++.h>
using namespace std;

struct Edge { int u, v; long long w; };

int par[100005], rnk[100005];

int find(int x) { return par[x] == x ? x : par[x] = find(par[x]); }

bool unite(int a, int b) {
    a = find(a); b = find(b);
    if (a == b) return false;
    if (rnk[a] < rnk[b]) swap(a, b);
    par[b] = a;
    if (rnk[a] == rnk[b]) rnk[a]++;
    return true;
}

int main() {
    ifstream in("CAPNUOC.INP");
    ofstream out("CAPNUOC.OUT");

    int n, m, k;
    in >> n >> m >> k;

    for (int i = 1; i <= n; i++) { par[i] = i; rnk[i] = 0; }

    vector<int> src(k);
    for (int i = 0; i < k; i++) in >> src[i];

    // Pre-merge all source cities
    for (int i = 1; i < k; i++) unite(src[0], src[i]);

    vector<Edge> edges(m);
    for (int i = 0; i < m; i++) in >> edges[i].u >> edges[i].v >> edges[i].w;

    sort(edges.begin(), edges.end(), [](const Edge& a, const Edge& b) {
        return a.w < b.w;
    });

    long long totalCost = 0;
    for (int i = 0; i < m; i++) {
        if (unite(edges[i].u, edges[i].v)) {
            totalCost += edges[i].w;
        }
    }

    // Check if all connected
    int root = find(1);
    bool connected = true;
    for (int i = 2; i <= n; i++) {
        if (find(i) != root) { connected = false; break; }
    }

    if (connected) out << totalCost;
    else out << -1;

    in.close();
    out.close();
    return 0;
}
