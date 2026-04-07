#include <bits/stdc++.h>
using namespace std;

long long robLine(vector<long long> &a, int l, int r) {
    int sz = r - l + 1;
    vector<long long> dp(sz);
    dp[0] = a[l];
    if(sz > 1) dp[1] = max(a[l], a[l + 1]);
    for(int i = 2; i < sz; i++)
        dp[i] = max(dp[i - 1], dp[i - 2] + a[l + i]);
    return dp[sz - 1];
}

int main() {
    ifstream in("TROMNHA.INP");
    ofstream out("TROMNHA.OUT");
    int n;
    in >> n;
    vector<long long> a(n);
    for(int i = 0; i < n; i++) in >> a[i];
    out << max(robLine(a, 0, n - 2), robLine(a, 1, n - 1));
    in.close();
    out.close();
    return 0;
}
