// Bai 3: LICHHOP — Sort + DP + Binary Search O(N log N)
#include <bits/stdc++.h>
using namespace std;

struct Meeting {
    int s, e;
    long long w;
};

int main() {
    ifstream in("LICHHOP.INP");
    ofstream out("LICHHOP.OUT");

    int n;
    in >> n;
    vector<Meeting> m(n);
    for (int i = 0; i < n; i++) in >> m[i].s >> m[i].e >> m[i].w;

    // Sort by end time
    sort(m.begin(), m.end(), [](const Meeting& a, const Meeting& b) {
        return a.e < b.e;
    });

    // dp[i] = max weight considering first i meetings (1-indexed)
    vector<long long> dp(n + 1, 0);
    for (int i = 0; i < n; i++) {
        // Binary search: largest j with m[j].e <= m[i].s
        int lo = 0, hi = i - 1, p = -1;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (m[mid].e <= m[i].s) { p = mid; lo = mid + 1; }
            else hi = mid - 1;
        }
        dp[i + 1] = max(dp[i], dp[p + 1] + m[i].w);
    }

    out << dp[n];

    in.close();
    out.close();
    return 0;
}
