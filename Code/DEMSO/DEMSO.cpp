// Bai 1: DEMSO — Sieve of Eratosthenes O(R log log R)
#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream in("DEMSO.INP");
    ofstream out("DEMSO.OUT");

    int l, r;
    in >> l >> r;

    vector<bool> sieve(r + 1, true);
    sieve[0] = sieve[1] = false;
    for (int i = 2; (long long)i * i <= r; i++)
        if (sieve[i])
            for (int j = i * i; j <= r; j += i)
                sieve[j] = false;

    int cnt = 0;
    for (int i = l; i <= r; i++)
        if (sieve[i]) cnt++;

    out << cnt;

    in.close();
    out.close();
    return 0;
}
