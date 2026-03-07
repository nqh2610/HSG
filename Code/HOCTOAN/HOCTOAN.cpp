#include <bits/stdc++.h>
using namespace std;
int main() {
    ifstream cin("HOCTOAN.INP");
    ofstream cout("HOCTOAN.OUT");
    long long a, b;
    if (!(cin >> a >> b)) return 0;
    // Dieu kien can de ton tai x, y la b phai chia het cho a
    if (b % a != 0) {
        cout << -1;
        return 0;
    }
    long long m = b / a;
    long long min_sum = -1;
    long long res_x = -1, res_y = -1;
    // Duyet u la uoc cua m
    for (long long u = 1; u * u <= m; u++) {
        if (m % u == 0) {
            long long v = m / u;
            // Kiem tra u va v co nguyen to cung nhau khong
            if (__gcd(u, v) == 1) {
                long long x = a * u;
                long long y = a * v;
                // Tim x + y nho nhat
                if (min_sum == -1 || (x + y) < min_sum) {
                    min_sum = x + y;
                    res_x = x;
                    res_y = y;
                }
            }
        }
    }
    if (min_sum == -1) {
        cout << -1;
    } else {
        cout << min_sum << endl;
        // Xuat x nho hon truoc theo yeu cau de bai
        if (res_x < res_y) cout << res_x << " " << res_y;
        else cout << res_y << " " << res_x;
    }
    return 0;
}
