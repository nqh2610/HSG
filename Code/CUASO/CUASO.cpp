// Bài 1: CUASO — Sliding Window O(N)
#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream in("CUASO.INP");
    ofstream out("CUASO.OUT");

    int n;
    long long s;
    in >> n >> s;

    vector<long long> a(n);
    for (int i = 0; i < n; i++) in >> a[i];

    int ans = n + 1;
    long long sum = 0;
    int left = 0;

    for (int right = 0; right < n; right++) {
        sum += a[right];
        while (sum >= s) {
            ans = min(ans, right - left + 1);
            sum -= a[left];
            left++;
        }
    }

    out << (ans == n + 1 ? 0 : ans);

    in.close();
    out.close();
    return 0;
}
