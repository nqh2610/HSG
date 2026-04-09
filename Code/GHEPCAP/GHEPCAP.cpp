// Bai 1: GHEPCAP — Sort + Greedy O(N log N)
#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream in("GHEPCAP.INP");
    ofstream out("GHEPCAP.OUT");

    int n;
    in >> n;
    vector<int> a(2 * n);
    for (int i = 0; i < 2 * n; i++) in >> a[i];

    sort(a.begin(), a.end());

    long long ans = 0;
    for (int i = 0; i < 2 * n; i += 2)
        ans += a[i + 1] - a[i];

    out << ans;

    in.close();
    out.close();
    return 0;
}
