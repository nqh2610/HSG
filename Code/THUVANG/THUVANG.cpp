// Bai 3: THUVANG — DP 1D O(N)
#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream in("THUVANG.INP");
    ofstream out("THUVANG.OUT");

    int n;
    in >> n;
    vector<long long> a(n + 1);
    for (int i = 1; i <= n; i++) in >> a[i];

    vector<long long> dp(n + 1, 0);
    dp[1] = a[1];
    if (n >= 2) dp[2] = a[1] + a[2];
    for (int i = 3; i <= n; i++)
        dp[i] = a[i] + max(dp[i - 1], dp[i - 2]);

    out << dp[n];

    in.close();
    out.close();
    return 0;
}
