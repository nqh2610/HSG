#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream in("CHAMBAI.INP");
    ofstream out("CHAMBAI.OUT");

    int n, K;
    in >> n >> K;
    vector<long long> a(n);
    long long lo = 0, hi = 0;
    for (int i = 0; i < n; i++) {
        in >> a[i];
        lo = max(lo, a[i]);
        hi += a[i];
    }

    while (lo < hi) {
        long long mid = (lo + hi) / 2;
        // Greedy: can we split into <= K segments, each sum <= mid?
        int segments = 1;
        long long sum = 0;
        for (int i = 0; i < n; i++) {
            if (sum + a[i] > mid) {
                segments++;
                sum = a[i];
            } else {
                sum += a[i];
            }
        }
        if (segments <= K)
            hi = mid;
        else
            lo = mid + 1;
    }

    out << lo;

    in.close();
    out.close();
    return 0;
}
