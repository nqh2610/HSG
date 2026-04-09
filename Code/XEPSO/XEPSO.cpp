// Bai 2: XEPSO — Subset Sum DP O(N*S)
#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream in("XEPSO.INP");
    ofstream out("XEPSO.OUT");

    int n;
    in >> n;
    vector<int> a(n);
    int S = 0;
    for (int i = 0; i < n; i++) { in >> a[i]; S += a[i]; }

    int half = S / 2;
    vector<bool> dp(half + 1, false);
    dp[0] = true;

    for (int i = 0; i < n; i++) {
        for (int j = half; j >= a[i]; j--) {
            if (dp[j - a[i]]) dp[j] = true;
        }
    }

    for (int j = half; j >= 0; j--) {
        if (dp[j]) {
            out << S - 2 * j;
            break;
        }
    }

    in.close();
    out.close();
    return 0;
}
