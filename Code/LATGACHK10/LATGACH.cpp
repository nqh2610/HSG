#include <bits/stdc++.h>
using namespace std;

/*
    Bài LATGACH - Lát gạch viền (HSG K10 2024-2025)
    
    1. Ý tưởng:
    - Tìm độ rộng đường biên W lớn nhất sao cho số gạch không vượt quá T
    - Nhận xét: W càng tăng → số gạch càng nhiều (tính chất đơn điệu)
    - Áp dụng Tìm kiếm nhị phân để tìm W
    
    2. Công thức:
    - Số gạch = (Diện tích toàn bộ) - (Diện tích phần lõi không lát)
    - G = M*N - (M-2W)*(N-2W)
    - Thử W trong khoảng [1, min(M,N)/2]
    
    3. Lưu ý:
    - M, N lên đến 10^9, diện tích M*N có thể đạt 10^18 (vừa khít long long)
    - Dùng long double để tránh tràn số khi so sánh
*/

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ifstream cin("LATGACH.INP");
    ofstream cout("LATGACH.OUT");
    
    long long m, n, t;
    if (!(cin >> m >> n >> t)) return 0;
    
    long long low = 1, high = min(m, n) / 2;
    long long res = 0;
    
    while (low <= high) {
        long long w = low + (high - low) / 2;
        
        // Số gạch = M*N - (M-2W)*(N-2W)
        // Dùng long double để tránh tràn số
        long double toan_bo = (long double)m * n;
        long double loi = (long double)(m - 2 * w) * (n - 2 * w);
        long double gach = toan_bo - loi;
        
        if (gach <= (long double)t) {
            res = w;      // Lưu kết quả tốt nhất
            low = w + 1;  // Thử tăng W
        } else {
            high = w - 1; // Giảm W vì vượt quá số gạch cho phép
        }
    }
    
    cout << res;
    return 0;
}
