// Bài 1: CAPSO — Sort + Two Pointers O(N log N)
#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream in("CAPSO.INP");
    ofstream out("CAPSO.OUT");

    int n;
    long long s;
    in >> n >> s;

    vector<long long> a(n);
    for (int i = 0; i < n; i++) in >> a[i];

    sort(a.begin(), a.end());

    long long cnt = 0;
    int l = 0, r = n - 1;
    while (l < r) {
        if (a[l] + a[r] <= s) {
            cnt += r - l;
            l++;
        } else {
            r--;
        }
    }

    out << cnt;

    in.close();
    out.close();
    return 0;
}
