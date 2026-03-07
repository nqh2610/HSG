/*
    Câu 5: CHENHLECH - Chênh lệch (3 điểm)
    
    ĐỀ BÀI: Tìm xâu con liên tiếp có chênh lệch lớn nhất giữa 
            số lần xuất hiện nhiều nhất và ít nhất của các ký tự.
            Ký tự xuất hiện ít nhất phải xuất hiện >= 1 lần.
    
    Ý TƯỞNG:
    - Chỉ duyệt các ký tự thực sự xuất hiện trong xâu (tối ưu bộ nhớ và thời gian)
    - Duyệt tất cả cặp ký tự (c1, c2): c1 xuất hiện nhiều nhất, c2 ít nhất
    - Với mỗi cặp: tìm xâu con có count[c1] - count[c2] lớn nhất
    - Dùng kỹ thuật tìm đoạn con có tổng lớn nhất (biến thể Kadane)
    
    Độ phức tạp: O(N * k²) với k là số ký tự khác nhau trong xâu
*/

#include <bits/stdc++.h>
using namespace std;
int n;
string s;
ifstream in("CHENHLECH.INP");
ofstream out("CHENHLECH.OUT");

int main() {
    ios_base::sync_with_stdio(false);
    in.tie(NULL);    
    in >> n >> s;    
    // Tìm các ký tự xuất hiện trong xâu
    vector<char> kyTu;
    vector<bool> daCo(26, false);
    for (int i = 0; i < n; i++) {
        if (!daCo[s[i] - 'a']) {
            daCo[s[i] - 'a'] = true;
            kyTu.push_back(s[i]);
        }
    }    
    int ketQua = 0;    
    // Duyệt tất cả cặp ký tự (c1, c2) CHỈ trong các ký tự xuất hiện
    for (char c1 : kyTu) {
        for (char c2 : kyTu) {
            if (c1 == c2) continue;            
            // Tìm xâu con có (số c1) - (số c2) lớn nhất, với c2 xuất hiện >= 1 lần
            int diff = 0;
            int minDiff = 0;        // diff nhỏ nhất tại vị trí trước c2 gần nhất
            int minDiffTemp = 0;    // diff nhỏ nhất tạm thời
            bool coC2 = false;            
            for (int i = 0; i < n; i++) {
                if (s[i] == c1) diff++;
                else if (s[i] == c2) diff--;                
                // Khi gặp c2, cập nhật minDiff
                if (s[i] == c2) {
                    coC2 = true;
                    minDiff = min(minDiff, minDiffTemp);
                }                
                minDiffTemp = min(minDiffTemp, diff);                
                // Tính kết quả nếu đã có c2 trong đoạn
                if (coC2) {
                    ketQua = max(ketQua, diff - minDiff);
                }
            }
        }
    }    
    out << ketQua;    
    return 0;
}
