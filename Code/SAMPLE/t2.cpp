#include <bits/stdc++.h>
using namespace std;
int main() {
    ifstream in("NENNHA.INP");
    ofstream out("NENNHA.OUT");
    int n;
    in >> n;
    vector<vector<long long>> cost(n + 1, vector<long long>(3));
    for(int i = 1; i <= n; i++) in >> cost[i][0] >> cost[i][1] >> cost[i][2];
    vector<vector<long long>> dp(n + 1, vector<long long>(3, 0));
    for(int i = 1; i <= n; i++) {
        dp[i][0] = min(dp[i-1][1], dp[i-1][2]) + cost[i][0];
        dp[i][1] = min(dp[i-1][0], dp[i-1][2]) + cost[i][1];
        dp[i][2] = min(dp[i-1][0], dp[i-1][1]) + cost[i][2];
    }
    out << min({dp[n][0], dp[n][1], dp[n][2]});
    in.close(); out.close(); return 0;
}
