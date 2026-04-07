#include <bits/stdc++.h>
using namespace std;
int main() {
    ifstream in("DAYCON.INP");
    ofstream out("DAYCON.OUT");
    int n;
    in >> n;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++) in >> a[i];
    vector<int> dp(n + 1, 1);
    int ans = 1;
    for(int i = 2; i <= n; i++) {
        for(int j = 1; j < i; j++)
            if(a[j] < a[i])
                dp[i] = max(dp[i], dp[j] + 1);
        ans = max(ans, dp[i]);
    }
    out << ans;
    in.close(); out.close(); return 0;
}
