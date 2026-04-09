// Bai 1: AMTHUC — Prefix Sum + Map O(N log N)
#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream in("AMTHUC.INP");
    ofstream out("AMTHUC.OUT");

    int n;
    in >> n;

    map<long long, long long> cnt;
    long long prefix = 0, ans = 0;
    cnt[0] = 1;

    for (int i = 0; i < n; i++) {
        long long x;
        in >> x;
        prefix += x;
        ans += cnt[prefix];
        cnt[prefix]++;
    }

    out << ans;

    in.close();
    out.close();
    return 0;
}
