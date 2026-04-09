// Bai 2: DOITHI — Sort + Two Pointers O(N log N)
#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream in("DOITHI.INP");
    ofstream out("DOITHI.OUT");

    int n;
    long long d;
    in >> n >> d;

    vector<long long> a(n);
    for (int i = 0; i < n; i++) in >> a[i];

    sort(a.begin(), a.end());

    long long ans = 0;
    int left = 0;
    for (int right = 0; right < n; right++) {
        while (a[right] - a[left] > d) left++;
        ans += right - left;
    }

    out << ans;

    in.close();
    out.close();
    return 0;
}
