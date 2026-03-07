/*
    Bai 1: CO VAT - SAMPLE (HSG12_2016_HCM)
    Phien ban toi uu voi PRIORITY_QUEUE (Hang doi uu tien)
    
    Y tuong khac:
    1. Sap xep TUI theo dung tich TANG DAN
    2. Sap xep MAU theo khoi luong TANG DAN
    3. Duyet tung tui (tu nho den lon)
    4. Voi moi tui, dua tat ca mau co the chua vao heap
    5. Lay mau co gia tri CAO NHAT tu heap
*/

#include <bits/stdc++.h>
using namespace std;

struct Mau {
    int khoiLuong;
    int giaTri;
};

// Ham so sanh: sap xep theo khoi luong TANG DAN
bool cmpMau(Mau a, Mau b) {
    return a.khoiLuong < b.khoiLuong;
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
    for (int i = 0; i < M; i++) {
        in >> tui[i];
    }
    
    // Sap xep mau theo khoi luong TANG DAN
    sort(mau.begin(), mau.end(), cmpMau);    
    // Sap xep tui theo dung tich TANG DAN
    sort(tui.begin(), tui.end());    
    // Hang doi uu tien (max-heap) - tu dong dua gia tri lon len dau
    priority_queue<int> pq;    
    long long tongGiaTri = 0;
    int j = 0;  // Chi so mau dang xet
    
    // Duyet tung tui (tu nho den lon)
    for (int i = 0; i < M; i++) {
        // Dua tat ca mau co khoi luong <= dung tich tui vao heap
        while (j < N && mau[j].khoiLuong <= tui[i]) {
            pq.push(mau[j].giaTri);  // Chen gia tri vao heap
            j++;
        }        
        // Lay mau co gia tri cao nhat (neu co)
        if (!pq.empty()) {
            tongGiaTri += pq.top();  // Lay gia tri lon nhat
            pq.pop();                 // Xoa khoi heap
        }
    }    
    out << tongGiaTri;    
    return 0;
}

/*
    GIAI THICH PRIORITY_QUEUE:
    
    1. priority_queue<int> pq;
       - Hang doi uu tien (mac dinh la MAX-HEAP)
       - Phan tu LON NHAT luon o dau hang doi
    
    2. pq.push(x);
       - Chen x vao heap
    
    3. pq.top();
       - Lay gia tri LON NHAT (khong xoa)
    
    4. pq.pop();
       - Xoa phan tu lon nhat
    
    5. pq.empty();
       - Kiem tra heap rong hay khong
    
    VD: pq = {5, 10, 15, 20}
        pq.top() -> 20 (lon nhat)
        pq.pop() -> heap con {5, 10, 15}
    
    TAI SAO CACH NAY DUNG?
    - Duyet tui tu nho den lon
    - Voi moi tui, ta co danh sach cac mau co the chua
    - Chon mau co gia tri cao nhat (bang heap)
    - Mau da dung se bi xoa khoi heap
    
    VI DU:
    Mau: (5, 10), (100, 100)  [khoi luong, gia tri]
    Tui: 12
    
    Sap xep mau theo khoi luong: (5, 10), (100, 100)
    Sap xep tui: 12
    
    Xet tui 12:
    - Mau (5, 10) co khoi luong 5 <= 12 -> push(10)
    - Mau (100, 100) co khoi luong 100 > 12 -> dung
    - Heap = {10}
    - Lay top() = 10, pop()
    - Tong = 10
    
    Ket qua: 10
    
    DO PHUC TAP: O(N*logN + M*logM + N*logN) = O(N*logN)
*/
