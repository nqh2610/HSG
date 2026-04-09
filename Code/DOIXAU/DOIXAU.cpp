// Bai 2: DOIXAU — Edit Distance DP O(N*M), space O(M)
#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream in("DOIXAU.INP");
    ofstream out("DOIXAU.OUT");

    string a, b;
    in >> a >> b;

    int n = a.size(), m = b.size();
    vector<int> prev(m + 1), curr(m + 1);

    for (int j = 0; j <= m; j++) prev[j] = j;

    for (int i = 1; i <= n; i++) {
        curr[0] = i;
        for (int j = 1; j <= m; j++) {
            if (a[i - 1] == b[j - 1]) curr[j] = prev[j - 1];
            else curr[j] = 1 + min({prev[j - 1], prev[j], curr[j - 1]});
        }
        swap(prev, curr);
    }

    out << prev[m];

    in.close();
    out.close();
    return 0;
}
