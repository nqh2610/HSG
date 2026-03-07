#include <bits/stdc++.h>
using namespace std;
int main() {
    // Tối ưu tốc độ nhập xuất
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ifstream cin("BOIBA.INP");
    ofstream cout("BOIBA.OUT");
    int n;
    if (!(cin >> n)) return 0;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    long long tong_da_cong = 0;
    long long ket_qua = 0;
    for (int i = 0; i < n; i++) {
        // Giá trị thực tế của số sau khi chịu ảnh hưởng bởi các lần cộng trước
        long long gia_tri_hien_tai = a[i] + tong_da_cong;
        int du = gia_tri_hien_tai % 3;
        if (du != 0) {
            int v = 3 - du; // Lượng cần cộng thêm để chia hết cho 3
            tong_da_cong += v; // Cập nhật tổng đã cộng để các số sau sử dụng
            ket_qua += (long long)v * (n - i); // v được cộng cho (n-i) số tính từ i
        }
    }
    cout << ket_qua;
    return 0;
}
