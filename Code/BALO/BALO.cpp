// Bài 2: BALO — DP Knapsack 2D (weight + volume) O(N*W*V)
#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream in("BALO.INP");
    ofstream out("BALO.OUT");

    int n, W, V;
    in >> n >> W >> V;

    vector<int> w(n), s(n), p(n);
    for (int i = 0; i < n; i++) in >> w[i] >> s[i] >> p[i];

    // dp[j][k] = max value with weight <= j, volume <= k
    vector<vector<long long> > dp(W + 1, vector<long long>(V + 1, 0));
    for (int i = 0; i < n; i++) {
        for (int j = W; j >= w[i]; j--) {
            for (int k = V; k >= s[i]; k--) {
                dp[j][k] = max(dp[j][k], dp[j - w[i]][k - s[i]] + (long long)p[i]);
            }
        }
    }

    out << dp[W][V];

    in.close();
    out.close();
    return 0;
}
