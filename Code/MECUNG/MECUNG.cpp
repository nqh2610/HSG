#include <bits/stdc++.h>
using namespace std;

int m, n, K;
char a[1001][1001];
int dist[1001][1001][6];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

struct State {
    int x, y, k;
};

void BFS_Luoi() {
    memset(dist, -1, sizeof(dist));
    dist[0][0][0] = 0;
    queue<State> q;
    q.push({0, 0, 0});

    while (!q.empty()) {
        int x = q.front().x, y = q.front().y, k = q.front().k;
        q.pop();
        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d], ny = y + dy[d];
            if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;

            if (a[nx][ny] != '#') {
                if (dist[nx][ny][k] == -1) {
                    dist[nx][ny][k] = dist[x][y][k] + 1;
                    q.push({nx, ny, k});
                }
            } else if (k + 1 <= K && dist[nx][ny][k + 1] == -1) {
                dist[nx][ny][k + 1] = dist[x][y][k] + 1;
                q.push({nx, ny, k + 1});
            }
        }
    }
}

int main() {
    ifstream in("MECUNG.INP");
    ofstream out("MECUNG.OUT");
    in >> m >> n >> K;
    for (int i = 0; i < m; i++) {
        string row;
        in >> row;
        for (int j = 0; j < n; j++)
            a[i][j] = row[j];
    }

    BFS_Luoi();

    int ans = -1;
    for (int k = 0; k <= K; k++) {
        if (dist[m-1][n-1][k] != -1) {
            if (ans == -1 || dist[m-1][n-1][k] < ans)
                ans = dist[m-1][n-1][k];
        }
    }

    out << ans;

    in.close();
    out.close();
    return 0;
}
