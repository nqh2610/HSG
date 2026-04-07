#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<pair<int,int>>> ke, ke_nguoc;
vector<long long> dist;
vector<bool> Free;

void Dijkstra(int S) {
    dist.assign(n + 1, LLONG_MAX);
    Free.assign(n + 1, true);
    priority_queue<pair<long long,int>,
                   vector<pair<long long,int>>,
                   greater<pair<long long,int>>> pq;
    dist[S] = 0; pq.push(make_pair(0LL, S));

    while (!pq.empty()) {
        long long d = pq.top().first; int u = pq.top().second; pq.pop();
        if (!Free[u]) continue;
        Free[u] = false;
        for (int i = 0; i < (int)ke[u].size(); i++) {
            int v = ke[u][i].first, w = ke[u][i].second;
            if (Free[v] && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push(make_pair(dist[v], v));
            }
        }
    }
}

int main() {
    ifstream in("DUONGUU.INP");
    ofstream out("DUONGUU.OUT");
    in >> n >> m;

    ke.assign(n + 1, vector<pair<int,int>>());
    ke_nguoc.assign(n + 1, vector<pair<int,int>>());
    vector<int> eu(m), ev(m);

    for (int i = 0; i < m; i++) {
        int w;
        in >> eu[i] >> ev[i] >> w;
        ke[eu[i]].push_back(make_pair(ev[i], w));
        ke_nguoc[ev[i]].push_back(make_pair(eu[i], w));
    }

    // Dijkstra lần 1: từ đỉnh 1 trên đồ thị gốc
    Dijkstra(1);
    vector<long long> dist1 = dist;

    // Dijkstra lần 2: từ đỉnh N trên đồ thị ngược
    swap(ke, ke_nguoc);
    Dijkstra(n);
    // dist chính là distN

    // Thử dùng VIP trên từng cạnh u→v: bỏ trọng số w
    // Chi phí = dist1[u] + 0 + distN[v]
    long long ans = dist1[n]; // không dùng VIP
    for (int i = 0; i < m; i++) {
        if (dist1[eu[i]] != LLONG_MAX && dist[ev[i]] != LLONG_MAX)
            ans = min(ans, dist1[eu[i]] + dist[ev[i]]);
    }

    if (ans == LLONG_MAX) out << -1;
    else out << ans;

    in.close();
    out.close();
    return 0;
}
