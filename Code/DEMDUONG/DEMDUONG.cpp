// Bai 3: DEMDUONG — Grid DP + Big Number Addition O(N*M*digits)
#include <bits/stdc++.h>
using namespace std;

string addBig(const string& a, const string& b) {
    if (a == "0") return b;
    if (b == "0") return a;
    string res;
    int carry = 0, i = a.size() - 1, j = b.size() - 1;
    while (i >= 0 || j >= 0 || carry) {
        int s = carry;
        if (i >= 0) s += a[i--] - '0';
        if (j >= 0) s += b[j--] - '0';
        res += (char)('0' + s % 10);
        carry = s / 10;
    }
    reverse(res.begin(), res.end());
    return res;
}

int main() {
    ifstream in("DEMDUONG.INP");
    ofstream out("DEMDUONG.OUT");

    int n, m, k;
    in >> n >> m >> k;

    vector<vector<bool>> blk(n + 1, vector<bool>(m + 1, false));
    for (int i = 0; i < k; i++) {
        int r, c; in >> r >> c;
        blk[r][c] = true;
    }

    vector<string> prev(m + 1, "0"), curr(m + 1, "0");

    if (!blk[1][1]) prev[1] = "1";
    for (int j = 2; j <= m; j++) {
        if (!blk[1][j]) prev[j] = prev[j - 1];
    }

    for (int i = 2; i <= n; i++) {
        for (int j = 0; j <= m; j++) curr[j] = "0";
        for (int j = 1; j <= m; j++) {
            if (blk[i][j]) continue;
            curr[j] = prev[j];
            if (j > 1) curr[j] = addBig(curr[j], curr[j - 1]);
        }
        swap(prev, curr);
    }

    out << prev[m];

    in.close();
    out.close();
    return 0;
}
