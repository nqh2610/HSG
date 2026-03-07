#include <bits/stdc++.h>
using namespace std;

/*
    Bài BANGNHAU - Olympic 11 TP.HCM 2023-2024
    
    1. Ý tưởng:
    - Với n lên tới 10^5, không thể dùng hai vòng lặp lồng nhau O(n^2)
    - Sắp xếp dãy số tăng dần → các số bằng nhau nằm cạnh nhau thành nhóm
    - Duyệt qua dãy một lần:
        + Nếu số hiện tại = số trước → tăng biến đếm
        + Nếu khác → kết thúc nhóm, cập nhật kỷ lục nếu cần
    - In ra số lượng lớn nhất (k) và giá trị (x)
    
    2. Lưu ý:
    - a[i] lên tới 10^9 → dùng int đủ
    - n = 10^5 → thuật toán sắp xếp O(n log n)
*/

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ifstream cin("BANGNHAU.INP");
    ofstream cout("BANGNHAU.OUT");
    
    int n;
    if (!(cin >> n)) return 0;
    
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    
    // Sắp xếp để các số giống nhau đứng cạnh nhau
    sort(a.begin(), a.end());
    
    int k = 1;      // Số lượng lớn nhất
    int x = a[0];   // Giá trị tương ứng
    int dem = 1;    // Biến đếm cho nhóm hiện tại
    
    for (int i = 1; i < n; i++) {
        if (a[i] == a[i - 1]) {
            // Số hiện tại giống số trước → tăng đếm
            dem++;
        } else {
            // Kết thúc một nhóm, cập nhật kỷ lục nếu cần
            if (dem > k) {
                k = dem;
                x = a[i - 1];
            }
            dem = 1;  // Reset đếm cho nhóm mới
        }
    }
    
    // Kiểm tra nhóm cuối cùng
    if (dem > k) {
        k = dem;
        x = a[n - 1];
    }
    
    cout << k << " " << x;
    return 0;
}
