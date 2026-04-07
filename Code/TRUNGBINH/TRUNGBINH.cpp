#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream in("TRUNGBINH.INP");
    ofstream out("TRUNGBINH.OUT");

    int n;
    long long K;
    in >> n >> K;

    long long prefix = 0;
    map<long long, long long> cnt;
    cnt[0] = 1;
    long long ans = 0;

    for (int i = 0; i < n; i++) {
        long long a;
        in >> a;
        prefix += a - K;
        ans += cnt[prefix];
        cnt[prefix]++;
    }

    out << ans;

    in.close();
    out.close();
    return 0;
}
