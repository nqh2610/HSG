// Bai 3: MANG — Offline Sort + DSU O((M+Q) log(M+Q))
#include <bits/stdc++.h>
using namespace std;

struct Edge { int u, v, w; };
struct Query { int u, v, t, idx; };

int par[100005], rnk[100005];

int find(int x) { return par[x] == x ? x : par[x] = find(par[x]); }

void unite(int a, int b) {
    a = find(a); b = find(b);
    if (a == b) return;
    if (rnk[a] < rnk[b]) swap(a, b);
    par[b] = a;
    if (rnk[a] == rnk[b]) rnk[a]++;
}

int main() {
    ifstream in("MANG.INP");
    ofstream out("MANG.OUT");

    int n, m, q;
    in >> n >> m >> q;

    vector<Edge> edges(m);
    for (int i = 0; i < m; i++) in >> edges[i].u >> edges[i].v >> edges[i].w;

    vector<Query> queries(q);
    for (int i = 0; i < q; i++) {
        in >> queries[i].u >> queries[i].v >> queries[i].t;
        queries[i].idx = i;
    }

    sort(edges.begin(), edges.end(), [](const Edge& a, const Edge& b) { return a.w > b.w; });
    sort(queries.begin(), queries.end(), [](const Query& a, const Query& b) { return a.t > b.t; });

    for (int i = 1; i <= n; i++) { par[i] = i; rnk[i] = 0; }

    vector<string> ans(q);
    int ei = 0;
    for (int i = 0; i < q; i++) {
        while (ei < m && edges[ei].w >= queries[i].t) {
            unite(edges[ei].u, edges[ei].v);
            ei++;
        }
        ans[queries[i].idx] = (find(queries[i].u) == find(queries[i].v)) ? "YES" : "NO";
    }

    for (int i = 0; i < q; i++) out << ans[i] << "\n";

    in.close();
    out.close();
    return 0;
}
