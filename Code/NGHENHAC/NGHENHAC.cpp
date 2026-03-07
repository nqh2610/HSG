#include <bits/stdc++.h>
using namespace std;
int main() {
    // Tang toc nhap xuat cho du lieu lon
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    ifstream cin("NGHENHAC.INP");
    ofstream cout("NGHENHAC.OUT");
    int n;
    long long k;
    if (!(cin >> n >> k)) return 0;
    vector<int> m(n);
    for (int i = 0; i < n; i++) cin >> m[i];
    long long sum = 0;
    int L = 0, max_len = 0;
    for (int R = 0; R < n; R++) {
        sum += m[R];
        // Neu tong thoi gian vuot qua k, thu nho cua so tu ben trai
        while (sum > k && L <= R) {
            sum -= m[L];
            L++;
        }
        // Cap nhat do dai day bai hat lien tiep dai nhat
        max_len = max(max_len, R - L + 1);
    }
    cout << max_len;
    return 0;
}
