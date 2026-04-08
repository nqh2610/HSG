// Bài 2: DEMUOC — Sieve (SPF) + Divisor Count
#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream in("DEMUOC.INP");
    ofstream out("DEMUOC.OUT");

    int n, k;
    in >> n >> k;

    // Sieve of smallest prime factor
    vector<int> spf(n + 1, 0);
    for (int i = 2; i <= n; i++) {
        if (spf[i] == 0) {
            for (int j = i; j <= n; j += i) {
                if (spf[j] == 0) spf[j] = i;
            }
        }
    }

    int cnt = 0;
    for (int x = 1; x <= n; x++) {
        // Compute number of divisors from prime factorization
        int d = 1;
        int tmp = x;
        while (tmp > 1) {
            int p = spf[tmp];
            int e = 0;
            while (tmp % p == 0) {
                tmp /= p;
                e++;
            }
            d *= (e + 1);
        }
        if (d == k) cnt++;
    }

    out << cnt;

    in.close();
    out.close();
    return 0;
}
