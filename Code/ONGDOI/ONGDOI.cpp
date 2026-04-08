// Bai 3: ONGDOI — Max Flow (Dinic) O(V^2 * E)
#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e18;
const int MAXV = 510;

struct Edge {
    int to, rev;
    long long cap;
};

vector<Edge> graph[MAXV];
int level[MAXV], iter_[MAXV];

void add_edge(int from, int to, long long cap) {
    graph[from].push_back({to, (int)graph[to].size(), cap});
    graph[to].push_back({from, (int)graph[from].size() - 1, 0});
}

bool bfs(int s, int t) {
    memset(level, -1, sizeof(level));
    queue<int> q;
    level[s] = 0;
    q.push(s);
    while (!q.empty()) {
        int v = q.front(); q.pop();
        for (int i = 0; i < (int)graph[v].size(); i++) {
            Edge& e = graph[v][i];
            if (e.cap > 0 && level[e.to] < 0) {
                level[e.to] = level[v] + 1;
                q.push(e.to);
            }
        }
    }
    return level[t] >= 0;
}

long long dfs(int v, int t, long long f) {
    if (v == t) return f;
    for (int& i = iter_[v]; i < (int)graph[v].size(); i++) {
        Edge& e = graph[v][i];
        if (e.cap > 0 && level[v] < level[e.to]) {
            long long d = dfs(e.to, t, min(f, e.cap));
            if (d > 0) {
                e.cap -= d;
                graph[e.to][e.rev].cap += d;
                return d;
            }
        }
    }
    return 0;
}

long long max_flow(int s, int t) {
    long long flow = 0;
    while (bfs(s, t)) {
        memset(iter_, 0, sizeof(iter_));
        long long d;
        while ((d = dfs(s, t, INF)) > 0)
            flow += d;
    }
    return flow;
}

int main() {
    ifstream in("ONGDOI.INP");
    ofstream out("ONGDOI.OUT");

    int n, m;
    in >> n >> m;

    for (int i = 0; i < m; i++) {
        int u, v;
        long long c;
        in >> u >> v >> c;
        add_edge(u, v, c);
    }

    out << max_flow(1, n);

    in.close();
    out.close();
    return 0;
}
