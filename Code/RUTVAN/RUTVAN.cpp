#include <bits/stdc++.h>
using namespace std;

/*
    BAI TOAN RUT VAN - MST tren luoi
    
    Y tuong:
    - Luoi co (N+1) cot va (M+1) hang, tao thanh (N+1)*(M+1) o
    - Rut van de noi tat ca cac o voi chi phi nho nhat
    
    Cach giai:
    1. Tinh do rong moi cot (doRongCot[]) va do cao moi hang (doCaoHang[])
    2. Sort ca 2 mang
    3. Duyet theo thu tu trong so tang dan (two pointers):
       - Voi moi gia tri trong so w, dem so cot (nCol) va so hang (nRow) co gia tri = w
       - Chi phi = w * (nCol * (soHang - 1) + nRow * (soCot - 1))
       - Cap nhat: soCot -= nRow, soHang -= nCol
*/

int main() {
    ifstream fin("RUTVAN.INP");
    ofstream fout("RUTVAN.OUT");
    
    long long A, B;
    int N, M;
    fin >> A >> B >> N >> M;
    
    vector<long long> a(N), b(M);
    for (int i = 0; i < N; i++) fin >> a[i];
    for (int i = 0; i < M; i++) fin >> b[i];
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    
    // Tinh do rong cac cot
    vector<long long> doRongCot;
    if (N == 0) {
        doRongCot.push_back(A);
    } else {
        doRongCot.push_back(a[0]);
        for (int i = 1; i < N; i++) {
            doRongCot.push_back(a[i] - a[i-1]);
        }
        doRongCot.push_back(A - a[N-1]);
    }
    
    // Tinh do cao cac hang
    vector<long long> doCaoHang;
    if (M == 0) {
        doCaoHang.push_back(B);
    } else {
        doCaoHang.push_back(b[0]);
        for (int i = 1; i < M; i++) {
            doCaoHang.push_back(b[i] - b[i-1]);
        }
        doCaoHang.push_back(B - b[M-1]);
    }
    
    // Sort ca 2 mang
    sort(doRongCot.begin(), doRongCot.end());
    sort(doCaoHang.begin(), doCaoHang.end());
    
    long long soCot = N + 1;
    long long soHang = M + 1;
    
    long long tongDoDai = 0;
    int i = 0, j = 0;
    
    while (i < (int)doRongCot.size() || j < (int)doCaoHang.size()) {
        // Tim gia tri nho nhat
        long long w;
        if (i >= (int)doRongCot.size()) {
            w = doCaoHang[j];
        } else if (j >= (int)doCaoHang.size()) {
            w = doRongCot[i];
        } else {
            w = min(doRongCot[i], doCaoHang[j]);
        }
        
        // Dem so cot va so hang co gia tri = w
        long long nCol = 0, nRow = 0;
        while (i < (int)doRongCot.size() && doRongCot[i] == w) {
            nCol++;
            i++;
        }
        while (j < (int)doCaoHang.size() && doCaoHang[j] == w) {
            nRow++;
            j++;
        }
        
        // Tinh chi phi:
        // - nCol cot, moi cot them (soHang - 1) canh doc
        // - nRow hang, moi hang them (soCot - 1) canh ngang
        tongDoDai += w * (nCol * (soHang - 1) + nRow * (soCot - 1));
        
        // Cap nhat so cot va so hang con lai
        soCot -= nRow;
        soHang -= nCol;
    }
    
    fout << tongDoDai;
    return 0;
}
