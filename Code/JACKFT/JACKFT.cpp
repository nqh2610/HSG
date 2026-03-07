/*  
    Cong thuc do dai day: 2 * (x[j] - x[i]) + soCay * D
    Y tuong: Sap xep theo vi tri + Two Pointers
*/

#include <bits/stdc++.h>
using namespace std;
struct Cay {
    long long viTri;
    long long soQua;
};

bool cmpCay(Cay a, Cay b) {
    return a.viTri < b.viTri;
}
int main() {
    ifstream in("JACKFT.INP");
    ofstream out("JACKFT.OUT");    
    int N;
    long long L, D;
    in >> N >> L >> D;    
    vector<Cay> cay(N);
    for (int i = 0; i < N; i++) {
        in >> cay[i].viTri;
    }
    for (int i = 0; i < N; i++) {
        in >> cay[i].soQua;
    }    
    sort(cay.begin(), cay.end(), cmpCay);    
    long long ketQua = 0;
    long long tongQua = 0;
    int i = 0;    
    for (int j = 0; j < N; j++) {
        tongQua += cay[j].soQua;        
        while (i <= j) {
            int soCay = j - i + 1;
            long long doDai = 2 * (cay[j].viTri - cay[i].viTri) + soCay * D;            
            if (doDai <= L) break;            
            tongQua -= cay[i].soQua;
            i++;
        }        
        if (tongQua > ketQua) {
            ketQua = tongQua;
        }
    }    
    out << ketQua;    
    return 0;
}
