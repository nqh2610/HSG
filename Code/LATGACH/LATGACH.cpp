#include <bits/stdc++.h>
using namespace std;

/*
    Bài LATGACH - Lát gạch (HSG 12 TP.HCM 2022-2023)
    
    ĐỀ BÀI:
    - Có N viên gạch hình chữ nhật, mỗi viên có tọa độ (x, y) và kích thước (d x c)
    - Hai viên gạch thuộc cùng KHU VỰC nếu chúng CHẠM NHAU (có điểm chung)
    - Tìm TỔNG DIỆN TÍCH LỚN NHẤT của một khu vực
    
    Ý TƯỞNG:
    1. Dùng DSU (Disjoint Set Union) để gộp các viên gạch chạm nhau vào cùng tập hợp
    2. Mỗi tập hợp = 1 khu vực, lưu tổng diện tích của khu vực đó
    3. Duyệt tất cả các cặp gạch, nếu chạm nhau thì gộp lại
    4. Cuối cùng tìm khu vực có tổng diện tích lớn nhất
    
    KIỂM TRA 2 GẠCH CHẠM NHAU:
    - Gạch A: từ (x1, y1) đến (x1+d1, y1+c1)
    - Gạch B: từ (x2, y2) đến (x2+d2, y2+c2)
    - Chạm nhau nếu: max(x1,x2) <= min(x1+d1, x2+d2) VÀ max(y1,y2) <= min(y1+c1, y2+c2)
    
    TỐI ƯU:
    - Sắp xếp gạch theo tọa độ x
    - Khi duyệt, nếu gạch j nằm xa hơn gạch i theo trục x thì dừng sớm (break)  
  
*/

// Cấu trúc lưu thông tin một viên gạch
struct VienGach {
    int id;
    long long x, y, d, c, dienTich;
};
const int MAXN = 50005;
int cha[MAXN];
long long tongDienTich[MAXN];
// Ham tim goc cua tap hop (co toi uu nen duong di)
int tim_goc(int v) {
    if (v == cha[v]) return v;
    return cha[v] = tim_goc(cha[v]);
}
// Ham gop hai tap hop va cong don dien tich
void hop_nhat(int a, int b) {
    a = tim_goc(a);
    b = tim_goc(b);
    if (a != b) {
        cha[b] = a;
        tongDienTich[a] += tongDienTich[b];
    }
}
// Ham kiem tra hai vien gach co cham nhau hoac chung goc khong
bool kiem_tra_cham(VienGach a, VienGach b) {
    return max(a.x, b.x) <= min(a.x + a.d, b.x + b.d) &&
           max(a.y, b.y) <= min(a.y + a.c, b.y + b.c);
}
int main() {
    // Tang toc do nhap xuat cho du lieu lon
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    ifstream cin("LATGACH.INP");
    ofstream cout("LATGACH.OUT");
    int n;
    if (!(cin >> n)) return 0;
    vector<VienGach> dsGach(n);
    for (int i = 0; i < n; i++) {
        dsGach[i].id = i;
        cin >> dsGach[i].x >> dsGach[i].y >> dsGach[i].d >> dsGach[i].c;
        dsGach[i].dienTich = dsGach[i].d * dsGach[i].c;        
        // Khoi tao DSU
        cha[i] = i;
        tongDienTich[i] = dsGach[i].dienTich;
    }
    // Sap xep theo toa do x de toi uu vong lap so sanh
    sort(dsGach.begin(), dsGach.end(), [](VienGach a, VienGach b) {
        return a.x < b.x;
    });
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            // Neu toa do x cua vien j da vuot qua pham vi cua vien i thi dung lai
            if (dsGach[j].x > dsGach[i].x + dsGach[i].d) break;            
            if (kiem_tra_cham(dsGach[i], dsGach[j])) {
                hop_nhat(dsGach[i].id, dsGach[j].id);
            }
        }
    }
    long long kq_lon_nhat = 0;
    for (int i = 0; i < n; i++) {
        if (cha[i] == i) { // Chi xet cac nut goc cua khu vuc
            if (tongDienTich[i] > kq_lon_nhat) {
                kq_lon_nhat = tongDienTich[i];
            }
        }
    }
    cout << kq_lon_nhat;
    return 0;
}
