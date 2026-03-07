/*
    Bài 2: CHANGE - Đổi quà (HSG12_2018)
    
    ĐỀ BÀI: Đếm số cách dùng N phiếu đổi quà (giá từ 1 đến K).
    
    Ý TƯỞNG:
    - Quy hoạch động: soCach[j] = số cách đạt tổng j
    - Duyệt từng giá trị từ 1 đến k, mỗi giá trị được dùng nhiều lần
    - Với mỗi giá trị, cập nhật: soCach[j] += soCach[j - gia]
    - Kết quả: soCach[n]
    
    Độ phức tạp: O(n * k)
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream in("CHANGE.INP");
    ofstream out("CHANGE.OUT");
    
    int n, k;
    in >> n >> k;
    
    // soCach[j] = so cach dat tong = j
    vector<long long> soCach(n + 1, 0);
    soCach[0] = 1;
    
    for (int gia = 1; gia <= k; gia++) {
        for (int j = gia; j <= n; j++) {
            soCach[j] += soCach[j - gia];
        }
    }
    
    out << soCach[n];
    
    return 0;
}
