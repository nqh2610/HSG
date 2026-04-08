// Bai 2: GIAITHUA — Big Number Multiply O(N * D)
#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream in("GIAITHUA.INP");
    ofstream out("GIAITHUA.OUT");

    int n;
    in >> n;

    vector<int> result;
    result.push_back(1);

    for (int i = 2; i <= n; i++) {
        long long carry = 0;
        for (int j = 0; j < (int)result.size(); j++) {
            long long prod = (long long)result[j] * i + carry;
            result[j] = prod % 10;
            carry = prod / 10;
        }
        while (carry > 0) {
            result.push_back(carry % 10);
            carry /= 10;
        }
    }

    for (int i = (int)result.size() - 1; i >= 0; i--)
        out << result[i];

    in.close();
    out.close();
    return 0;
}
