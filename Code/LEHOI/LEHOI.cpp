/*
    Bai 2: LEHOI - Le hoi (HSG12_2026)
    Thue N thiet bi, chia thanh nhom:
    - Nhom >= 3: mien phi 1 cai nho nhat
    - Nhom < 3: tat ca giam q%
    Tim chi phi nho nhat    
    Cach giai: 
    - Sort giam dan
    - DP: chi xet nhom 1, 2, hoac 3 (nhom lon hon chia nho luon tot hon)
*/

#include <bits/stdc++.h>
using namespace std;
int main() {
    ifstream in("LEHOI.INP");
    ofstream out("LEHOI.OUT");    
    int n, q;
    in >> n >> q;    
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        in >> a[i];
    }    
    // Sort giam dan
    sort(a.begin(), a.end(), greater<long long>());    
    // giam = ti le phai tra neu nhom < 3
    double giam = (100.0 - q) / 100.0;    
    // dp[i] = chi phi toi thieu de thue i thiet bi dau tien
    vector<double> dp(n + 1, 1e18);
    dp[0] = 0;    
    for (int i = 1; i <= n; i++) {
        // Nhom 1: chi lay a[i-1]
        dp[i] = min(dp[i], dp[i-1] + a[i-1] * giam);        
        // Nhom 2: lay a[i-2], a[i-1]
        if (i >= 2) {
            dp[i] = min(dp[i], dp[i-2] + (a[i-2] + a[i-1]) * giam);
        }        
        // Nhom 3: lay a[i-3], a[i-2], a[i-1], mien a[i-1] (nho nhat)
        if (i >= 3) {
            dp[i] = min(dp[i], dp[i-3] + a[i-3] + a[i-2]);
        }
    }    
    out << (long long)round(dp[n]);    
    return 0;
}
