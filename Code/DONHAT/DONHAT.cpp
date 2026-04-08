#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream in("DONHAT.INP");
    ofstream out("DONHAT.OUT");

    int n;
    long long S;
    in >> n >> S;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) in >> a[i];

    int ans = n + 1;
    long long sum = 0;
    int l = 0;

    for (int r = 0; r < n; r++) {
        sum += a[r];
        while (sum >= S) {
            ans = min(ans, r - l + 1);
            sum -= a[l];
            l++;
        }
    }

    if (ans == n + 1) out << -1;
    else out << ans;

    in.close();
    out.close();
    return 0;
}
