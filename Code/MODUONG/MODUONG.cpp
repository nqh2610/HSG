// Bai 3: MODUONG — 0-1 BFS O(N*M)
#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream in("MODUONG.INP");
    ofstream out("MODUONG.OUT");

    int n, m;
    in >> n >> m;
    vector<string> grid(n);
    for (int i = 0; i < n; i++) in >> grid[i];

    vector<vector<int> > d(n, vector<int>(m, 1000000));
    deque<pair<int, int> > dq;
    d[0][0] = 0;
    dq.push_front(make_pair(0, 0));

    int dx[] = {0, 0, 1, -1};
    int dy[] = {1, -1, 0, 0};

    while (!dq.empty()) {
        int x = dq.front().first, y = dq.front().second;
        dq.pop_front();
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            int w = (grid[nx][ny] == '#') ? 1 : 0;
            if (d[x][y] + w < d[nx][ny]) {
                d[nx][ny] = d[x][y] + w;
                if (w == 0) dq.push_front(make_pair(nx, ny));
                else dq.push_back(make_pair(nx, ny));
            }
        }
    }

    out << d[n - 1][m - 1];

    in.close();
    out.close();
    return 0;
}
