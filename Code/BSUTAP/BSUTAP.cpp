// Bai 3: BSUTAP — Sliding Window O(N)
#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream in("BSUTAP.INP");
    ofstream out("BSUTAP.OUT");

    int n, k;
    in >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; i++) in >> a[i];

    int freq[100001] = {};
    int distinct = 0, ans = 0, left = 0;

    for (int right = 0; right < n; right++) {
        if (freq[a[right]] == 0) distinct++;
        freq[a[right]]++;

        while (distinct > k) {
            freq[a[left]]--;
            if (freq[a[left]] == 0) distinct--;
            left++;
        }

        if (right - left + 1 > ans) ans = right - left + 1;
    }

    out << ans;

    in.close();
    out.close();
    return 0;
}
