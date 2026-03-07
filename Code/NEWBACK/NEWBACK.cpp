/*
    Bài 3: NEWBACK - Ba lô kiểu mới (HSG12_2018)
    
    ĐỀ BÀI: Ba lô sức chứa v0. Nếu tổng thể tích V > v0 thì áp lực = V - v0.
            Mỗi vật chịu được áp lực tối đa. Tìm tổng giá trị lớn nhất.
    
    Ý TƯỞNG:
    - Sắp xếp các vật theo áp lực chịu được tăng dần
    - Duyệt từng vật làm "điểm nghẽn" (vật có áp lực nhỏ nhất trong tập chọn)
    - Với vật thứ bat làm điểm nghẽn: giới hạn thể tích = v0 + apLuc[bat]
    - Chỉ xét các vật từ bat trở đi (có apLuc >= apLuc[bat])
    - Chạy QHĐ ba lô 0/1 trên tập này, cập nhật max
    
    Độ phức tạp: O(n² * V)
*/

#include <bits/stdc++.h>
using namespace std;

struct Vat {
    int theTich, gia, apLuc;
};

bool soSanh(Vat a, Vat b) {
    return a.apLuc < b.apLuc;
}

int main() {
    ifstream in("NEWBACK.INP");
    ofstream out("NEWBACK.OUT");
    
    int n, v0;
    in >> n >> v0;
    
    vector<Vat> vat(n);
    for (int i = 0; i < n; i++) {
        in >> vat[i].theTich >> vat[i].gia >> vat[i].apLuc;
    }
    
    sort(vat.begin(), vat.end(), soSanh);
    
    long long maxGia = 0;
    
    for (int bat = 0; bat < n; bat++) {
        int gioi = v0 + vat[bat].apLuc;
        
        vector<long long> f(gioi + 1, 0);
        
        for (int j = bat; j < n; j++) {
            for (int t = gioi; t >= vat[j].theTich; t--) {
                f[t] = max(f[t], f[t - vat[j].theTich] + vat[j].gia);
            }
        }
        
        for (int t = 0; t <= gioi; t++) {
            if (f[t] > maxGia) maxGia = f[t];
        }
    }
    
    out << maxGia;
    
    return 0;
}
