// Bài 2: DOIXUNG — DP Palindrome O(N^2)
#include <bits/stdc++.h>
using namespace std;

int dp[5001][5001]; // dp[i][j] = LPS of s[i..j]

int main() {
    ifstream in("DOIXUNG.INP");
    ofstream out("DOIXUNG.OUT");

    string s;
    in >> s;
    int n = s.size();

    // Base: single characters
    for (int i = 0; i < n; i++) dp[i][i] = 1;

    // Fill by increasing length
    for (int len = 2; len <= n; len++) {
        for (int i = 0; i <= n - len; i++) {
            int j = i + len - 1;
            if (s[i] == s[j]) {
                dp[i][j] = dp[i + 1][j - 1] + 2;
            } else {
                dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
            }
        }
    }

    // Min insertions = |S| - LPS
    out << n - dp[0][n - 1];

    in.close();
    out.close();
    return 0;
}
