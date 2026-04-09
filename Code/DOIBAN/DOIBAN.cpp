// Bai 2: DOIBAN — Counting O(N)
#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream in("DOIBAN.INP");
    ofstream out("DOIBAN.OUT");

    int n;
    in >> n;

    int freq[100001] = {};
    for (int i = 0; i < n; i++) {
        int x;
        in >> x;
        freq[x]++;
    }

    long long ans = 0;
    for (int c = 1; c <= 100000; c++) {
        if (freq[c] >= 2)
            ans += (long long)freq[c] * (freq[c] - 1) / 2;
    }

    out << ans;

    in.close();
    out.close();
    return 0;
}
