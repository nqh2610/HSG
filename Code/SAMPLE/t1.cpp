#include <bits/stdc++.h>
using namespace std;
int main() {
    ifstream in("XUONGNUI.INP");
    ofstream out("XUONGNUI.OUT");
    int n;
    in >> n;
    vector<vector<long long>> a(n + 1, vector<long long>(n + 1, 0));
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= i; j++)
            in >> a[i][j];
    vector<vector<long long>> dp(n + 1, vector<long long>(n + 1, 0));
    for(int j = 1; j <= n; j++) dp[n][j] = a[n][j];
    for(int i = n - 1; i >= 1; i--)
        for(int j = 1; j <= i; j++)
            dp[i][j] = a[i][j] + max(dp[i + 1][j], dp[i + 1][j + 1]);
    out << dp[1][1];
    in.close(); out.close(); return 0;
}
