#include <bits/stdc++.h>
using namespace std;

int n;
long long P[501];
long long dp[501][501];

int main() {
    ifstream in("TRONFILE.INP");
    ofstream out("TRONFILE.OUT");

    in >> n;
    for (int i = 1; i <= n; i++) {
        long long s;
        in >> s;
        P[i] = P[i - 1] + s;
    }

    // dp[i][j] = chi phi nho nhat tron file i..j
    for (int len = 2; len <= n; len++) {
        for (int i = 1; i + len - 1 <= n; i++) {
            int j = i + len - 1;
            dp[i][j] = LLONG_MAX;
            long long sum = P[j] - P[i - 1];
            for (int k = i; k < j; k++) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + sum);
            }
        }
    }

    out << dp[1][n];

    in.close();
    out.close();
    return 0;
}
