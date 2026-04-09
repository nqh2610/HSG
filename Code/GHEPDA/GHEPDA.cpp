// Bai 2: GHEPDA — Interval DP O(N^3)
#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream in("GHEPDA.INP");
    ofstream out("GHEPDA.OUT");

    int n;
    in >> n;
    vector<long long> a(n + 1), pre(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        in >> a[i];
        pre[i] = pre[i - 1] + a[i];
    }

    vector<vector<long long> > dp(n + 1, vector<long long>(n + 1, 0));
    for (int len = 2; len <= n; len++) {
        for (int i = 1; i + len - 1 <= n; i++) {
            int j = i + len - 1;
            dp[i][j] = 1e18;
            long long s = pre[j] - pre[i - 1];
            for (int k = i; k < j; k++)
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + s);
        }
    }

    out << dp[1][n];

    in.close();
    out.close();
    return 0;
}
