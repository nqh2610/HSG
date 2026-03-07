#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ifstream cin("PASSWORD.INP");
    ofstream cout("PASSWORD.OUT");
    string s;
    if (!(cin >> s)) return 0;
    int n = s.length();
    int posHoa = -1, posThuong = -1, posSo = -1;
    long long dem = 0;
    for (int j = 0; j < n; j++) {
        // Cap nhat vi tri gan nhat cua tung loai
        if (isupper(s[j])) posHoa = j;
        else if (islower(s[j])) posThuong = j;
        else if (isdigit(s[j])) posSo = j;
        // Tim i sao cho [i, j] du 3 loai
        int i = min({posHoa, posThuong, posSo});
        if (i != -1) {
            // Diem bat dau k phai thoa man:
            // 1. k <= i (de du 3 loai)
            // 2. k <= j - 5 (de do dai >= 6)
            int k_max = min(i, j - 5);
            if (k_max >= 0) {
                dem += (k_max + 1);
            }
        }
    }
    cout << dem;
    return 0;
}
