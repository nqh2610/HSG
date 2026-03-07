/*
    Câu 1: DONGNUOC - Đong nước (5 điểm)
    
    ĐỀ BÀI: Có 3 cốc dung tích 5ml, 3ml, 2ml. 
            Tìm số lần đong ít nhất để được đúng N ml.
    
    Ý TƯỞNG:
    - Ưu tiên dùng cốc lớn nhất (5ml) để giảm số lần đong
    - Xét số dư khi chia N cho 5:
      + Dư 0: dùng N/5 cốc 5ml
      + Dư 1: bớt 1 cốc 5ml, thêm 2 cốc 3ml (vì 6 = 3+3)
      + Dư 2: thêm 1 cốc 2ml
      + Dư 3: thêm 1 cốc 3ml
      + Dư 4: thêm 2 cốc 2ml
    
    Độ phức tạp: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream in("DONGNUOC.INP");
    ofstream out("DONGNUOC.OUT");
    
    long long n;
    in >> n;
    
    long long du = n % 5;
    long long phan5 = n / 5;
    
    long long ketQua;
    
    if (du == 0) {
        ketQua = phan5;
    } else if (du == 1) {        
        ketQua = phan5 + 1;
    } else if (du == 2) {       
        ketQua = phan5 + 1;
    } else if (du == 3) {        
        ketQua = phan5 + 1;
    } else {        
        ketQua = phan5 + 2;
    }
    
    out << ketQua;    
    return 0;
}
