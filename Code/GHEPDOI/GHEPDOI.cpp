#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream in("GHEPDOI.INP");
    ofstream out("GHEPDOI.OUT");

    int n;
    in >> n;
    vector<long long> a(n), b(n);
    for (int i = 0; i < n; i++) in >> a[i];
    for (int i = 0; i < n; i++) in >> b[i];

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    long long ans = 0;
    for (int i = 0; i < n; i++) {
        ans += abs(a[i] - b[i]);
    }

    out << ans;

    in.close();
    out.close();
    return 0;
}
