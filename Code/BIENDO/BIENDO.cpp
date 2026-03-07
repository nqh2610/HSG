/*
    Bai 1: BIENDO - Bien do (HSG12_2026)
    Tinh tong bien do cua moi doan con lien tiep
    Bien do doan [i,j] = max(a[i..j]) - min(a[i..j])
    
    Cach giai: Tong bien do = Tong max - Tong min
    Dung Stack de tinh dong gop cua tung phan tu
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
    
    // Tinh tong max cua tat ca doan con
    // Voi moi a[i], tim so doan con ma a[i] la max
    // left[i] = vi tri gan nhat ben trai co a > a[i]
    // right[i] = vi tri gan nhat ben phai co a >= a[i]
    // So doan co a[i] la max = (i - left[i]) * (right[i] - i)
    
    vector<int> trai(n), phai(n);
    stack<int> st;
    
    // Tim left: phan tu lon hon gan nhat ben trai
    for (int i = 0; i < n; i++) {
        while (!st.empty() && a[st.top()] <= a[i]) {
            st.pop();
        }
        trai[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }
    
    // Xoa stack
    while (!st.empty()) st.pop();
    
    // Tim right: phan tu lon hon hoac bang gan nhat ben phai
    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && a[st.top()] < a[i]) {
            st.pop();
        }
        phai[i] = st.empty() ? n : st.top();
        st.push(i);
    }
    
    long long tongMax = 0;
    for (int i = 0; i < n; i++) {
        long long soTrai = i - trai[i];      // So vi tri trai (ke ca i)
        long long soPhai = phai[i] - i;      // So vi tri phai (ke ca i)
        tongMax += a[i] * soTrai * soPhai;
    }
    
    // Tinh tong min tuong tu, nhung tim phan tu nho hon
    while (!st.empty()) st.pop();
    
    // Tim left: phan tu nho hon gan nhat ben trai
    for (int i = 0; i < n; i++) {
        while (!st.empty() && a[st.top()] >= a[i]) {
            st.pop();
        }
        trai[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }
    
    while (!st.empty()) st.pop();
    
    // Tim right: phan tu nho hon hoac bang gan nhat ben phai
    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && a[st.top()] > a[i]) {
            st.pop();
        }
        phai[i] = st.empty() ? n : st.top();
        st.push(i);
    }
    
    long long tongMin = 0;
    for (int i = 0; i < n; i++) {
        long long soTrai = i - trai[i];
        long long soPhai = phai[i] - i;
        tongMin += a[i] * soTrai * soPhai;
    }
    
    out << tongMax - tongMin;
    
    return 0;
}
