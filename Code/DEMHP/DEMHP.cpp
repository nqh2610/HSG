// Bai 2: DEMHP — Digit DP O(19 * K)
#include <bits/stdc++.h>
using namespace std;

int K, len, d[19];
long long memo[19][201][2];

long long solve(int pos, int sum, int tight) {
    if (pos == len) return sum == 0 ? 1 : 0;
    if (memo[pos][sum][tight] != -1) return memo[pos][sum][tight];
    int lim = tight ? d[pos] : 9;
    long long res = 0;
    for (int x = 0; x <= lim; x++)
        res += solve(pos + 1, (sum + x) % K, tight && x == lim);
    return memo[pos][sum][tight] = res;
}

long long count(long long x) {
    if (x < 0) return 0;
    string s = to_string(x);
    len = s.size();
    for (int i = 0; i < len; i++) d[i] = s[i] - '0';
    memset(memo, -1, sizeof(memo));
    return solve(0, 0, 1);
}

int main() {
    ifstream in("DEMHP.INP");
    ofstream out("DEMHP.OUT");

    long long L, R;
    in >> L >> R >> K;

    out << count(R) - count(L - 1);

    in.close();
    out.close();
    return 0;
}
