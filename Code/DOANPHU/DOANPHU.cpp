// Bai 3: DOANPHU — Coordinate Compression + Sweep O(N log N)
#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream in("DOANPHU.INP");
    ofstream out("DOANPHU.OUT");

    int n;
    in >> n;
    vector<int> l(n), r(n);
    vector<int> coords;
    for (int i = 0; i < n; i++) {
        in >> l[i] >> r[i];
        coords.push_back(l[i]);
        coords.push_back(r[i]);
    }

    // Nen toa do
    sort(coords.begin(), coords.end());
    coords.erase(unique(coords.begin(), coords.end()), coords.end());
    int K = coords.size();

    // Diff array tren toa do nen
    vector<int> diff(K + 1, 0);
    for (int i = 0; i < n; i++) {
        int cl = lower_bound(coords.begin(), coords.end(), l[i]) - coords.begin();
        int cr = lower_bound(coords.begin(), coords.end(), r[i]) - coords.begin();
        diff[cl]++;
        diff[cr]--;
    }

    // Prefix sum, tinh tong chieu dai
    long long ans = 0;
    int cnt = 0;
    for (int i = 0; i < K - 1; i++) {
        cnt += diff[i];
        if (cnt > 0)
            ans += coords[i + 1] - coords[i];
    }

    out << ans;

    in.close();
    out.close();
    return 0;
}
