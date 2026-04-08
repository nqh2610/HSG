// Bai 1: DEMCAP — Counting Array (Remainder frequency) O(N + K)
#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream in("DEMCAP.INP");
    ofstream out("DEMCAP.OUT");

    int n, k;
    in >> n >> k;

    vector<long long> cnt(k, 0);
    for (int i = 0; i < n; i++) {
        long long a;
        in >> a;
        cnt[a % k]++;
    }

    long long ans = cnt[0] * (cnt[0] - 1) / 2;
    for (int r = 1; r * 2 < k; r++) {
        ans += cnt[r] * cnt[k - r];
    }
    if (k % 2 == 0) {
        ans += cnt[k / 2] * (cnt[k / 2] - 1) / 2;
    }

    out << ans;

    in.close();
    out.close();
    return 0;
}
