// Bai 2: DEMXAU — Dem xau con (Distinct Subsequences)
#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
int dp[5001][5001];

int main() {
    ifstream in("DEMXAU.INP");
    ofstream out("DEMXAU.OUT");

    string S, T;
    in >> S >> T;
    int n = S.size(), m = T.size();

    for (int i = 0; i <= n; i++) dp[i][0] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            dp[i][j] = dp[i - 1][j];
            if (S[i - 1] == T[j - 1])
                dp[i][j] = (dp[i][j] + dp[i - 1][j - 1]) % MOD;
        }
    }

    out << dp[n][m];

    in.close();
    out.close();
    return 0;
}
