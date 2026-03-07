#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ifstream cin("KHUYENMAI.INP");
    ofstream cout("KHUYENMAI.OUT");
    int n, k_limit;
    if (!(cin >> n >> k_limit)) return 0;
    vector<int> a;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int tmp;
            cin >> tmp;
            a.push_back(tmp);
        }
    }
    sort(a.begin(), a.end());
    int L = 0, R = a.size() - 1;
    int maxM = 0;
    while (L < R) {
        int sum = a[L] + a[R];
        if (sum <= k_limit) {
            if (sum > maxM) maxM = sum;
            L++; // Tang gia tri nho de tim tong lon hon
        } else {
            R--; // Giam gia tri lon de sum nho lai
        }
    }
    cout << maxM;
    return 0;
}
