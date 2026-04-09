// Bai 1: CHIAVIEC — Binary Search on Answer O(N log S)
#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream in("CHIAVIEC.INP");
    ofstream out("CHIAVIEC.OUT");

    int n, k;
    in >> n >> k;
    vector<long long> a(n);
    long long lo = 0, hi = 0;
    for (int i = 0; i < n; i++) {
        in >> a[i];
        lo = max(lo, a[i]);
        hi += a[i];
    }

    while (lo < hi) {
        long long mid = (lo + hi) / 2;
        int cnt = 1;
        long long sum = 0;
        for (int i = 0; i < n; i++) {
            if (sum + a[i] > mid) {
                cnt++;
                sum = a[i];
            } else {
                sum += a[i];
            }
        }
        if (cnt <= k) hi = mid;
        else lo = mid + 1;
    }

    out << lo;

    in.close();
    out.close();
    return 0;
}
