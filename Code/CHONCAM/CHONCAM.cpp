#include <bits/stdc++.h>
using namespace std;
int main() {
    ifstream cin("CHONCAM.INP");
    ofstream cout("CHONCAM.OUT");
    int n;
    if (!(cin >> n)) return 0;
    vector<pair<int, int>> khay(n);
    for (int i = 0; i < n; i++) {
        cin >> khay[i].first >> khay[i].second;
    }
    int maxKetQua = 0;
    int loaiTotNhat = 1;
    // Duyet qua 5 loai cam tu 1 den 5
    for (int loai = 1; loai <= 5; loai++) {
        int demHienTai = 0;
        int maxLoaiNay = 0;
        for (int i = 0; i < n; i++) {
            // Neu khay i co chua loai cam dang xet
            if (khay[i].first == loai || khay[i].second == loai) {
                demHienTai++;
                if (demHienTai > maxLoaiNay) maxLoaiNay = demHienTai;
            } else {
                demHienTai = 0; // Bi ngat quang, dem lai tu dau
            }
        }
        // Luu lai loai cam co day lien tiep dai nhat
        if (maxLoaiNay > maxKetQua) {
            maxKetQua = maxLoaiNay;
            loaiTotNhat = loai;
        }
    }
    cout << maxKetQua << " " << loaiTotNhat;
    return 0;
}
