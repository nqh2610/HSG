/*
    Bài 1: AVERAGE - Trung bình cộng (HSG12_2018)
    
    ĐỀ BÀI: Tìm đoạn liên tiếp dài nhất có trung bình cộng bằng k.
    
    Ý TƯỞNG:
    - Đoạn có trung bình = k <=> tổng (a[i] - k) của đoạn đó = 0
    - Dùng tổng tiền tố: nếu 2 vị trí có tổng tiền tố bằng nhau 
      thì đoạn giữa có tổng = 0
    - Dùng map lưu vị trí ĐẦU TIÊN xuất hiện mỗi giá trị tổng
    - Khi gặp lại giá trị đã có => tính độ dài, cập nhật max
    
    Độ phức tạp: O(n log n)
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream in("AVERAGE.INP");
    ofstream out("AVERAGE.OUT");    
    int n;
    long long k;
    in >> n >> k;    
    vector<long long> keo(n);
    for (int i = 0; i < n; i++) {
        in >> keo[i];
    }    
    // tong[i] = (keo[0]-k) + (keo[1]-k) + ... + (keo[i-1]-k)
    // Neu tong[i] = tong[j] thi doan [i, j-1] co trung binh = k
    map<long long, int> viTri; // Luu vi tri dau tien xuat hien tong
    viTri[0] = 0;    
    long long tong = 0;
    int daiNhat = 0;    
    for (int i = 0; i < n; i++) {
        tong += keo[i] - k;        
        if (viTri.count(tong)) {
            int doDai = i + 1 - viTri[tong];
            if (doDai > daiNhat) daiNhat = doDai;
        } else {
            viTri[tong] = i + 1;
        }
    }
    
    out << daiNhat;
    
    return 0;
}
