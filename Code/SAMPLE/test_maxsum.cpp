#include <bits/stdc++.h>
using namespace std;
int main() {
    ifstream in("MAXSUM.INP");
    ofstream out("MAXSUM.OUT");
    int n;
    in >> n;
    vector<long long> a(n + 1), dp(n + 1);
    for(int i = 1; i <= n; i++) in >> a[i];
    dp[1] = a[1];
    vector<int> start(n + 1);
    start[1] = 1;
    int bestL = 1, bestR = 1;
    long long bestSum = dp[1];
    for(int i = 2; i <= n; i++) {
        if(dp[i - 1] + a[i] >= a[i]) {
            dp[i] = dp[i - 1] + a[i];
            start[i] = start[i - 1];
        } else {
            dp[i] = a[i];
            start[i] = i;
        }
        if(dp[i] > bestSum) {
            bestSum = dp[i];
            bestL = start[i];
            bestR = i;
        }
    }
    out << bestSum << "\n";
    out << bestL << " " << bestR;
    in.close();
    out.close();
    return 0;
}
