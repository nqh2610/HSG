// Bài 3: CHIATAI — Meet-in-the-Middle + Sort + Binary Search
#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream in("CHIATAI.INP");
    ofstream out("CHIATAI.OUT");

    int n;
    in >> n;
    vector<long long> a(n);
    long long total = 0;
    for (int i = 0; i < n; i++) {
        in >> a[i];
        total += a[i];
    }

    // Split into 2 halves
    int h1 = n / 2, h2 = n - h1;

    // Enumerate all subset sums of first half
    vector<long long> sumA;
    for (int mask = 0; mask < (1 << h1); mask++) {
        long long s = 0;
        for (int i = 0; i < h1; i++)
            if (mask & (1 << i)) s += a[i];
        sumA.push_back(s);
    }
    sort(sumA.begin(), sumA.end());

    long long ans = total; // worst case: all in one group
    long long half = total / 2;

    // For each subset sum of second half, binary search in first half
    for (int mask = 0; mask < (1 << h2); mask++) {
        long long s = 0;
        for (int i = 0; i < h2; i++)
            if (mask & (1 << i)) s += a[h1 + i];

        // We want sumA[j] + s as close to total/2 as possible
        long long target = half - s;
        int pos = lower_bound(sumA.begin(), sumA.end(), target) - sumA.begin();

        // Check pos and pos-1
        for (int d = -1; d <= 0; d++) {
            int idx = pos + d;
            if (idx >= 0 && idx < (int)sumA.size()) {
                long long group1 = sumA[idx] + s;
                long long diff = abs(total - 2 * group1);
                ans = min(ans, diff);
            }
        }
    }

    out << ans;

    in.close();
    out.close();
    return 0;
}
