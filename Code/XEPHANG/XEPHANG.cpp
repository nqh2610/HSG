#include <bits/stdc++.h>
using namespace std;
// Cấu trúc lưu điểm của mỗi đội
struct Doi {
    int soBai = 0;
    long long diemPhat = 0;
};
Doi ds[100005];

bool totHon(Doi a, Doi b) {
    if (a.soBai != b.soBai) return a.soBai > b.soBai;
    return a.diemPhat < b.diemPhat;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); 
    ifstream cin("XEPHANG.INP");
    ofstream cout("XEPHANG.OUT");
    int n, m;
    cin >> n >> m;
    int soDoiTotHon = 0; 
    for (int i = 0; i < m; i++) {
        int t, p;
        cin >> t >> p;
        Doi cu = ds[t]; 
        ds[t].soBai++;
        ds[t].diemPhat += p;
        if (t == 1) {         
            soDoiTotHon = 0;
            for (int j = 2; j <= n; j++) {
                if (totHon(ds[j], ds[1])) soDoiTotHon++;
            }
        } else {
          
            bool truocDayTotHon = totHon(cu, ds[1]);
            bool hienTaiTotHon = totHon(ds[t], ds[1]);
            if (!truocDayTotHon && hienTaiTotHon) soDoiTotHon++;
            else if (truocDayTotHon && !hienTaiTotHon) soDoiTotHon--; 
        }
        cout << soDoiTotHon + 1 << "\n";
    }
    return 0;
}

