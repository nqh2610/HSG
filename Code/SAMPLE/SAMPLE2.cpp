/*
    Bai 1: CO VAT - SAMPLE (HSG12_2016_HCM)
    Phien ban toi uu voi MULTISET
    
    Y tuong: Tham lam (Greedy)
    1. Uu tien lay mau co gia tri CAO truoc
    2. Voi moi mau, chon tui NHO NHAT co the chua duoc
    3. Dung multiset de tim va xoa nhanh O(logM)
*/

#include <bits/stdc++.h>
using namespace std;

struct Mau {
    int khoiLuong;
    int giaTri;
};

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
    
    // multiset tu dong sap xep tang dan va cho phep trung lap
    multiset<int> tui;
    for (int i = 0; i < M; i++) {
        int c;
        in >> c;
        tui.insert(c);
    }   

    sort(mau.begin(), mau.end(), cmpMau);
    
    long long tongGiaTri = 0;
    
    // Duyet tung mau (tu gia tri cao nhat)
    for (int i = 0; i < N; i++) {
        // Tim tui nho nhat >= khoi luong mau
        // lower_bound(x) tra ve phan tu nho nhat >= x
        auto it = tui.lower_bound(mau[i].khoiLuong);
        
        // Neu tim thay tui phu hop
        if (it != tui.end()) {
            tongGiaTri += mau[i].giaTri;
            tui.erase(it);  // Xoa tui da dung
        }
    }
    
    out << tongGiaTri;
    
    return 0;
}

/*
    GIAI THICH MULTISET:
    
    1. multiset<int> tui;
       - Tap hop cac so nguyen, tu dong sap xep TANG DAN
       - Cho phep cac phan tu TRUNG LAP (khac set)
    
    2. tui.insert(x);
       - Chen x vao multiset
    
    3. tui.lower_bound(x);
       - Tim phan tu NHO NHAT >= x
       - Tra ve iterator (con tro) den phan tu do
       - Neu khong tim thay, tra ve tui.end()
    
    4. tui.erase(it);
       - Xoa phan tu tai vi tri it
    
    VD: tui = {5, 10, 15, 20}
        lower_bound(7)  -> tra ve iterator den 10
        lower_bound(10) -> tra ve iterator den 10
        lower_bound(25) -> tra ve end() (khong tim thay)
    
    DO PHUC TAP: O(N*logN + M*logM) - RẤT NHANH!
*/
