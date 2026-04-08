// Bai 1: TANGDIEM — Difference Array O(N + Q)
#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream in("TANGDIEM.INP");
    ofstream out("TANGDIEM.OUT");

    int n, q;
    in >> n >> q;

    vector<long long> d(n + 2, 0);
    for (int i = 0; i < q; i++) {
        int l, r;
        long long v;
        in >> l >> r >> v;
        d[l] += v;
        d[r + 1] -= v;
    }

    long long mx = 0, cur = 0;
    for (int i = 1; i <= n; i++) {
        cur += d[i];
        mx = max(mx, cur);
    }

    out << mx;

    in.close();
    out.close();
    return 0;
}
