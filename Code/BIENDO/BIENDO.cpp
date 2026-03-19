/*
    Bai 1: BIENDO - Bien do (HSG12_2026)
    
    DE BAI:
    - Cho day so A gom N phan tu
    - Bien do cua mot doan = max - min cua doan do
    - Tinh TONG bien do cua TAT CA doan con lien tiep
    
    INPUT:  Dong 1: N (so phan tu, N <= 10^6)
            Dong 2: N so nguyen A1, A2, ..., An (Ai <= 10^6)
    
    OUTPUT: Tong bien do cua moi doan con
    
    VD:     Input:  4
                    6 6 8 2
            Output: 22
    
    Y TUONG:
    - Tong bien do = Tong tat ca max - Tong tat ca min
    - Voi moi phan tu, dem no la MAX/MIN cua bao nhieu doan
    - Dung Stack giam dan de tim "vung anh huong" cua moi phan tu
    
    DO PHUC TAP: O(N)
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream in("BIENDO.INP");
    ofstream out("BIENDO.OUT");
    
    int n;
    in >> n;
    
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        in >> a[i];
    }
    
    // ========== TINH TONG MAX ==========
    // Voi moi a[i], tim so doan con ma a[i] la MAX
    // trai[i] = vi tri gan nhat ben trai co gia tri > a[i]
    // phai[i] = vi tri gan nhat ben phai co gia tri >= a[i]
    // So doan = (i - trai[i]) * (phai[i] - i)
    
    vector<int> trai(n), phai(n);
    stack<int> st;
    
    // Tim trai[i]: duyet tu trai sang phai, duy tri stack giam dan
    for (int i = 0; i < n; i++) {
        while (!st.empty() && a[st.top()] <= a[i]) {
            st.pop();  // Loai bo cac phan tu nho hon hoac bang
        }
        trai[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }
    
    while (!st.empty()) st.pop();  // Xoa stack de dung lai
    
    // Tim phai[i]: duyet tu phai sang trai
    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && a[st.top()] < a[i]) {
            st.pop();  // Loai bo cac phan tu nho hon
        }
        phai[i] = st.empty() ? n : st.top();
        st.push(i);
    }
    
    // Tinh tong dong gop cua moi phan tu voi tu cach la MAX
    long long tongMax = 0;
    for (int i = 0; i < n; i++) {
        long long soTrai = i - trai[i];  // So cach chon diem dau (ke ca i)
        long long soPhai = phai[i] - i;  // So cach chon diem cuoi (ke ca i)
        tongMax += a[i] * soTrai * soPhai;
    }
    
    // ========== TINH TONG MIN ==========
    // Tuong tu, nhung tim phan tu NHO HON
    
    while (!st.empty()) st.pop();
    
    // Tim trai[i]: phan tu nho hon gan nhat ben trai
    for (int i = 0; i < n; i++) {
        while (!st.empty() && a[st.top()] >= a[i]) {
            st.pop();
        }
        trai[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }
    
    while (!st.empty()) st.pop();
    
    // Tim phai[i]: phan tu nho hon gan nhat ben phai
    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && a[st.top()] > a[i]) {
            st.pop();
        }
        phai[i] = st.empty() ? n : st.top();
        st.push(i);
    }
    
    // Tinh tong dong gop cua moi phan tu voi tu cach la MIN
    long long tongMin = 0;
    for (int i = 0; i < n; i++) {
        long long soTrai = i - trai[i];
        long long soPhai = phai[i] - i;
        tongMin += a[i] * soTrai * soPhai;
    }
    
    // ========== KET QUA ==========
    out << tongMax - tongMin;
    
    return 0;
}
