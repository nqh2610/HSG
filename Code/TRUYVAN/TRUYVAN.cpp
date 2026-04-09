// Bai 1: TRUYVAN — Sparse Table O(N log N) build, O(1) query
#include <bits/stdc++.h>
using namespace std;

int sp[100001][17];
int Log2[100001];

int main() {
    ifstream in("TRUYVAN.INP");
    ofstream out("TRUYVAN.OUT");

    int n, q;
    in >> n >> q;
    for (int i = 1; i <= n; i++) in >> sp[i][0];

    Log2[1] = 0;
    for (int i = 2; i <= n; i++) Log2[i] = Log2[i / 2] + 1;

    for (int j = 1; (1 << j) <= n; j++)
        for (int i = 1; i + (1 << j) - 1 <= n; i++)
            sp[i][j] = min(sp[i][j - 1], sp[i + (1 << (j - 1))][j - 1]);

    for (int i = 0; i < q; i++) {
        int l, r;
        in >> l >> r;
        int k = Log2[r - l + 1];
        out << min(sp[l][k], sp[r - (1 << k) + 1][k]) << "\n";
    }

    in.close();
    out.close();
    return 0;
}
