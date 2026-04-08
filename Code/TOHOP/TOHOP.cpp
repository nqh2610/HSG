// Bai 2: TOHOP — Big Number C(N,K) exact
#include <bits/stdc++.h>
using namespace std;

typedef vector<int> BigNum;

BigNum fromInt(int x) {
    BigNum res;
    if (x == 0) { res.push_back(0); return res; }
    while (x > 0) { res.push_back(x % 10); x /= 10; }
    return res;
}

BigNum multiply(BigNum& a, int b) {
    BigNum res;
    long long carry = 0;
    for (int i = 0; i < (int)a.size(); i++) {
        long long prod = (long long)a[i] * b + carry;
        res.push_back(prod % 10);
        carry = prod / 10;
    }
    while (carry > 0) {
        res.push_back(carry % 10);
        carry /= 10;
    }
    return res;
}

BigNum divide(BigNum& a, int b) {
    BigNum res(a.size());
    long long carry = 0;
    for (int i = (int)a.size() - 1; i >= 0; i--) {
        carry = carry * 10 + a[i];
        res[i] = carry / b;
        carry = carry % b;
    }
    while (res.size() > 1 && res.back() == 0) res.pop_back();
    return res;
}

int main() {
    ifstream in("TOHOP.INP");
    ofstream out("TOHOP.OUT");

    int n, k;
    in >> n >> k;

    if (k > n - k) k = n - k;

    BigNum result = fromInt(1);
    for (int i = 1; i <= k; i++) {
        result = multiply(result, n - k + i);
        result = divide(result, i);
    }

    for (int i = (int)result.size() - 1; i >= 0; i--)
        out << result[i];

    in.close();
    out.close();
    return 0;
}
