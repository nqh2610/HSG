/*
    Câu 2: DAYCON - Dãy con (5 điểm)
    
    ĐỀ BÀI: Tìm dãy con liên tiếp ngắn nhất chứa ít nhất 2 số nguyên tố.
            Không tồn tại thì in -1.
    
    Ý TƯỞNG:
    - Sàng nguyên tố Eratosthenes đến 10^6
    - Duyệt dãy, lưu vị trí các số nguyên tố
    - Tìm 2 vị trí nguyên tố liên tiếp có khoảng cách nhỏ nhất
    - Đáp án = khoảng cách nhỏ nhất đó
    
    Độ phức tạp: O(N + MAX_VAL)
*/

#include <bits/stdc++.h>
using namespace std;

const int MAX_VAL = 1000001;
bool laNguyenTo[MAX_VAL];

void sangNguyenTo() {
    fill(laNguyenTo, laNguyenTo + MAX_VAL, true);
    laNguyenTo[0] = laNguyenTo[1] = false;
    for (int i = 2; i * i < MAX_VAL; i++) {
        if (laNguyenTo[i]) {
            for (int j = i * i; j < MAX_VAL; j += i) {
                laNguyenTo[j] = false;
            }
        }
    }
}

int main() {
    ifstream in("DAYCON.INP");
    ofstream out("DAYCON.OUT");
    
    sangNguyenTo();
    
    int n;
    in >> n;
    
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        in >> a[i];
    }
    
    // Tìm vị trí các số nguyên tố
    int viTriTruoc = -1;  // Vị trí số nguyên tố gần nhất trước đó
    int minDoDai = n + 1; // Độ dài nhỏ nhất
    
    for (int i = 0; i < n; i++) {
        if (laNguyenTo[a[i]]) {
            if (viTriTruoc != -1) {
                // Có 2 số nguyên tố: vị trí viTriTruoc và i
                int doDai = i - viTriTruoc + 1;
                if (doDai < minDoDai) {
                    minDoDai = doDai;
                }
            }
            viTriTruoc = i;
        }
    }
    
    if (minDoDai > n) {
        out << -1;
    } else {
        out << minDoDai;
    }
    
    return 0;
}
