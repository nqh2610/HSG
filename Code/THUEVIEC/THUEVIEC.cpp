// Bai 3: THUEVIEC — Sort + Binary Search + DP O(N log N)
#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream in("THUEVIEC.INP");
    ofstream out("THUEVIEC.OUT");

    int n;
    in >> n;

    vector<int> s(n), e(n);
    vector<long long> p(n);
    for (int i = 0; i < n; i++) in >> s[i] >> e[i] >> p[i];

    // Sort by end time
    vector<int> idx(n);
    for (int i = 0; i < n; i++) idx[i] = i;
    sort(idx.begin(), idx.end(), [&](int a, int b) {
        return e[a] < e[b];
    });

    vector<int> ends(n);
    for (int i = 0; i < n; i++) ends[i] = e[idx[i]];

    vector<long long> dp(n);
    dp[0] = p[idx[0]];

    for (int i = 1; i < n; i++) {
        int si = s[idx[i]];
        long long pi = p[idx[i]];

        // Find latest j with ends[j] < si
        int lo = 0, hi = i - 1, j = -1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (ends[mid] < si) {
                j = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }

        long long take = pi + (j >= 0 ? dp[j] : 0);
        dp[i] = max(dp[i - 1], take);
    }

    out << dp[n - 1];

    in.close();
    out.close();
    return 0;
}
