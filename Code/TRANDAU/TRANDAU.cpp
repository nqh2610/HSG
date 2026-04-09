// Bai 3: TRANDAU — Kadane O(N)
#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream in("TRANDAU.INP");
    ofstream out("TRANDAU.OUT");

    int n;
    in >> n;
    long long x, maxEnd, maxSoFar;
    in >> x;
    maxEnd = maxSoFar = x;

    for (int i = 1; i < n; i++) {
        in >> x;
        maxEnd = max(x, maxEnd + x);
        maxSoFar = max(maxSoFar, maxEnd);
    }

    out << maxSoFar;

    in.close();
    out.close();
    return 0;
}
