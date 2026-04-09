// Bai 2: THUHOACH — Binary Search on Answer O(N log S)
#include <bits/stdc++.h>
using namespace std;

int n, k;
long long a[100001];

bool check(long long mid) {
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
    return cnt <= k;
}

int main() {
    ifstream in("THUHOACH.INP");
    ofstream out("THUHOACH.OUT");

    in >> n >> k;
    long long lo = 0, hi = 0;
    for (int i = 0; i < n; i++) {
        in >> a[i];
        if (a[i] > lo) lo = a[i];
        hi += a[i];
    }

    while (lo < hi) {
        long long mid = (lo + hi) / 2;
        if (check(mid)) hi = mid;
        else lo = mid + 1;
    }

    out << lo;

    in.close();
    out.close();
    return 0;
}
