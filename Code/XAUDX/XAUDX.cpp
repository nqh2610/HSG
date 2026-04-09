// Bai 2: XAUDX — Min insertions = |S| - LCS(S, rev(S)), O(N^2) time O(N) space
#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream in("XAUDX.INP");
    ofstream out("XAUDX.OUT");

    string s;
    in >> s;
    int n = s.size();
    string t = s;
    reverse(t.begin(), t.end());

    vector<int> prev(n + 1, 0), curr(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (s[i - 1] == t[j - 1]) curr[j] = prev[j - 1] + 1;
            else curr[j] = max(prev[j], curr[j - 1]);
        }
        swap(prev, curr);
        fill(curr.begin(), curr.end(), 0);
    }

    out << n - prev[n];

    in.close();
    out.close();
    return 0;
}
