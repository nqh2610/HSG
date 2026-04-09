// Bai 1: TUOICAY — Difference Array O(N+M)
#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream in("TUOICAY.INP");
    ofstream out("TUOICAY.OUT");

    int n, m;
    in >> n >> m;

    vector<long long> diff(n + 2, 0);
    for (int i = 0; i < m; i++) {
        int l, r;
        long long v;
        in >> l >> r >> v;
        diff[l] += v;
        diff[r + 1] -= v;
    }

    long long mx = 0, cur = 0;
    for (int i = 1; i <= n; i++) {
        cur += diff[i];
        mx = max(mx, cur);
    }

    out << mx;

    in.close();
    out.close();
    return 0;
}
