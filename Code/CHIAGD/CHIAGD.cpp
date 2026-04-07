#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream in("CHIAGD.INP");
    ofstream out("CHIAGD.OUT");

    int n;
    long long S;
    in >> n >> S;

    vector<long long> P(n + 1, 0);
    for(int i = 1; i <= n; i++) {
        long long t;
        in >> t;
        P[i] = P[i - 1] + t;
    }

    // dp[i] = min(dp[j] + (P[i]-P[j])^2 + S)
    // dp[0] = -S (trick: giai đoạn đầu không nghỉ trước)
    vector<long long> dp(n + 1, 1e18);
    dp[0] = -S;

    for(int i = 1; i <= n; i++) {
        for(int j = 0; j < i; j++) {
            long long T = P[i] - P[j];
            long long cost = dp[j] + T * T + S;
            dp[i] = min(dp[i], cost);
        }
    }

    out << dp[n];
    in.close();
    out.close();
    return 0;
}
