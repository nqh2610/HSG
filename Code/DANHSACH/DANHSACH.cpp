// Bai 1: DANHSACH — Coordinate Compression + BIT O(N log N)
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;
int bit[MAXN], sz;

void update(int i) {
    for (; i <= sz; i += i & (-i)) bit[i]++;
}

int query(int i) {
    int s = 0;
    for (; i > 0; i -= i & (-i)) s += bit[i];
    return s;
}

int main() {
    ifstream in("DANHSACH.INP");
    ofstream out("DANHSACH.OUT");

    int n;
    in >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) in >> a[i];

    // Coordinate compression
    vector<int> v = a;
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    sz = v.size();

    for (int i = 0; i < n; i++) {
        int r = lower_bound(v.begin(), v.end(), a[i]) - v.begin() + 1;
        if (i) out << " ";
        out << query(r - 1);
        update(r);
    }

    in.close();
    out.close();
    return 0;
}
