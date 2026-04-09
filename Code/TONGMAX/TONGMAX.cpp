// Bai 2: TONGMAX — Kadane O(N)
#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream in("TONGMAX.INP");
    ofstream out("TONGMAX.OUT");

    int n;
    in >> n;

    long long cur = 0, ans;
    for (int i = 0; i < n; i++) {
        long long x;
        in >> x;
        cur += x;
        if (i == 0) ans = cur;
        else ans = max(ans, cur);
        if (cur < 0) cur = 0;
    }

    out << ans;

    in.close();
    out.close();
    return 0;
}
