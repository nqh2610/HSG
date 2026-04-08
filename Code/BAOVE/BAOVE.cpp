// Bai 3: BAOVE — Min Vertex Cut = Node Splitting + Max Flow (Dinic)
#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
const int MAXV = 1010;

struct Edge {
    int to, cap, rev;
};

vector<Edge> graph[MAXV];
int level[MAXV], iter_[MAXV];

void add_edge(int from, int to, int cap) {
    graph[from].push_back({to, cap, (int)graph[to].size()});
    graph[to].push_back({from, 0, (int)graph[from].size() - 1});
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

int dfs(int v, int t, int f) {
    if (v == t) return f;
    for (int& i = iter_[v]; i < (int)graph[v].size(); i++) {
        Edge& e = graph[v][i];
        if (e.cap > 0 && level[v] < level[e.to]) {
            int d = dfs(e.to, t, min(f, e.cap));
            if (d > 0) {
                e.cap -= d;
                graph[e.to][e.rev].cap += d;
                return d;
            }
        }
    }
    return 0;
}

int max_flow(int s, int t) {
    int flow = 0;
    while (bfs(s, t)) {
        memset(iter_, 0, sizeof(iter_));
        int d;
        while ((d = dfs(s, t, INF)) > 0)
            flow += d;
    }
    return flow;
}

int main() {
    ifstream in("BAOVE.INP");
    ofstream out("BAOVE.OUT");

    int n, m;
    in >> n >> m;

    // Node splitting: node v -> in-node v, out-node v+n
    for (int v = 1; v <= n; v++) {
        int cap = (v == 1 || v == n) ? INF : 1;
        add_edge(v, v + n, cap);
    }

    for (int i = 0; i < m; i++) {
        int u, v;
        in >> u >> v;
        add_edge(u + n, v, INF);
        add_edge(v + n, u, INF);
    }

    out << max_flow(1, n + n);

    in.close();
    out.close();
    return 0;
}
