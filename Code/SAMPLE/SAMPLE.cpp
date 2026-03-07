/*    
    Y tuong: Tham lam (Greedy)
    1. Uu tien lay mau co gia tri CAO truoc
    2. Voi moi mau, chon tui NHO NHAT co the chua duoc
    3. Chi dung mang va vong lap don gian
*/

#include <bits/stdc++.h>
using namespace std;

// Struct luu thong tin mau co vat
struct Mau {
    int khoiLuong;
    int giaTri;
};

// Ham so sanh: sap xep theo gia tri GIAM DAN
bool cmpMau(Mau a, Mau b) {
    return a.giaTri > b.giaTri;
}

int main() {
    ifstream in("SAMPLE.INP");
    ofstream out("SAMPLE.OUT");
    
    int N, M;
    in >> N >> M;    

    vector<Mau> mau(N);
    for (int i = 0; i < N; i++) {
        in >> mau[i].khoiLuong >> mau[i].giaTri;
    }   
  
    vector<int> tui(M);
    vector<bool> daDung(M, false);  // Danh dau tui da dung
    for (int i = 0; i < M; i++) {
        in >> tui[i];
    }    
    // Sap xep mau theo gia tri GIAM DAN
    sort(mau.begin(), mau.end(), cmpMau);    
    // Sap xep tui theo dung tich TANG DAN
    sort(tui.begin(), tui.end());    
    long long tongGiaTri = 0;
    
    // Duyet tung mau (tu gia tri cao nhat)
    for (int i = 0; i < N; i++) {
        // Tim tui nho nhat chua duoc va >= khoi luong mau
        for (int j = 0; j < M; j++) {
            // Neu tui chua dung VA chua duoc mau
            if (!daDung[j] && tui[j] >= mau[i].khoiLuong) {
                tongGiaTri += mau[i].giaTri;
                daDung[j] = true;  // Danh dau da dung
                break;  // Thoat, tim mau tiep theo
            }
        }
    }    
    out << tongGiaTri;    
    return 0;
}