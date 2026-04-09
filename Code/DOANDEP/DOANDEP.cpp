// Bai 2: DOANDEP — Two Pointers O(N)
#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream in("DOANDEP.INP");
    ofstream out("DOANDEP.OUT");

    int n;
    long long k;
    in >> n >> k;

    vector<long long> a(n);
    for (int i = 0; i < n; i++) in >> a[i];

    long long ans = 0, sum = 0;
    int l = 0;
    for (int r = 0; r < n; r++) {
        sum += a[r];
        while (sum > k) {
            sum -= a[l];
            l++;
        }
        ans += r - l + 1;
    }

    out << ans;

    in.close();
    out.close();
    return 0;
}
