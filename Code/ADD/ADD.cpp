/*
    Bai 3: PHEP CONG - ADD (HSG12_2016_HCM)
    
    Chen dau + vao A de A = S, dung it dau + nhat
    Y tuong: Quy hoach dong (DP)
    
    dp[i][j] =   so dau + it nhat de tong = j khi da xu ly i ky tu dau
*/

#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
int main() {
    ifstream in("ADD.INP");
    ofstream out("ADD.OUT");    
    string line;
    getline(in, line);
    
    // Tach A va S
    int pos = line.find('=');
    string A = line.substr(0, pos);
    int S = stoi(line.substr(pos + 1));
    int n = A.length();
    
    // dp[i][j] = so phan it nhat de tong = j, da dung i ky tu
    // trace[i][j] = vi tri truoc do
    vector<vector<int>> dp(n + 1, vector<int>(S + 1, INF));
    vector<vector<int>> trace(n + 1, vector<int>(S + 1, -1));
    
    dp[0][0] = 0;
    
    // Duyet tung vi tri trong A
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= S; j++) {
            if (dp[i][j] == INF) continue;
            
            // Thu cat so co do dai 1, 2, 3, 4, 5
            long long giaTri = 0;
            for (int len = 1; len <= 5 && i + len <= n; len++) {
                giaTri = giaTri * 10 + (A[i + len - 1] - '0');
                
                if (giaTri > S) break;
                
                int tongMoi = j + giaTri;
                if (tongMoi > S) break;
                
                // Cap nhat dp
                if (dp[i][j] + 1 < dp[i + len][tongMoi]) {
                    dp[i + len][tongMoi] = dp[i][j] + 1;
                    trace[i + len][tongMoi] = i;
                }
            }
        }
    }
    
    // Truy vet ket qua
    vector<string> cacSo;
    int curPos = n, curSum = S;
    
    while (curPos > 0) {
        int prevPos = trace[curPos][curSum];
        string so = A.substr(prevPos, curPos - prevPos);
        cacSo.push_back(so);
        
        // Tru di gia tri so vua lay
        long long giaTri = 0;
        for (char c : so) giaTri = giaTri * 10 + (c - '0');
        curSum -= giaTri;
        curPos = prevPos;
    }
    
    // In ket qua (dao nguoc vi truy vet tu cuoi)
    for (int i = cacSo.size() - 1; i >= 0; i--) {
        out << cacSo[i];
        if (i > 0) out << "+";
    }
    out << "=" << S;
    
    return 0;
}

/*
    GIAI THICH:
    
    1. dp[i][j] = so phan it nhat de:
       - Da xu ly i ky tu dau cua A
       - Tong cac so = j
    
    2. Chuyen trang thai:
       - Tu dp[i][j], cat them 1 so co len chu so (len = 1..5)
       - So do co gia tri = giaTri
       - Chuyen sang dp[i + len][j + giaTri]
    
    3. Truy vet:
       - Bat dau tu dp[n][S]
       - Dung trace de quay lui tim cac so
    
    VD: A = "2505", S = 30
    - dp[0][0] = 0
    - dp[1][2] = 1  (cat "2")
    - dp[2][25] = 1 (cat "25")
    - dp[3][25] = 2 (cat "2" + "5")
    - dp[4][30] = 2 (cat "25" + "05")
    
    Truy vet: dp[4][30] -> trace = 2 -> so "05"
              dp[2][25] -> trace = 0 -> so "25"
    Ket qua: 25+05=30
*/
