/*
    Câu 3: KHUDANCU - Khu dân cư (4 điểm)
    
    ĐỀ BÀI: Lưới M x N ô, mỗi ô là '.', 'P' (dân cư) hoặc 'M' (siêu thị).
            Siêu thị ở (x,y) phục vụ vùng vuông từ (x-D,y-D) đến (x+D,y+D).
            Đếm số khu dân cư được ít nhất K siêu thị phục vụ.
    
    Ý TƯỞNG:
    - Tạo bảng tổng cộng dồn: sum[i][j] = số siêu thị từ ô (1,1) đến ô (i,j)
    - Với mỗi khu dân cư P, đếm số siêu thị trong vùng xung quanh bằng 
      công thức: tổng = sum[dưới phải] - sum[trên phải] - sum[dưới trái] + sum[trên trái]
    - Nếu số siêu thị >= K thì đếm
    
    Độ phức tạp: O(M * N)
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream in("KHUDANCU.INP");
    ofstream out("KHUDANCU.OUT");
    
    int m, n, d, k;
    in >> m >> n >> d >> k;
    
    vector<string> banDo(m);
    for (int i = 0; i < m; i++) {
        in >> banDo[i];
    }
    
    // Tạo mảng đánh dấu siêu thị
    vector<vector<int>> sieuThi(m + 1, vector<int>(n + 1, 0));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (banDo[i][j] == 'M') {
                sieuThi[i + 1][j + 1] = 1;
            }
        }
    }
    
    // Tính prefix sum 2D
    // sum[i][j] = tổng số siêu thị trong vùng từ (1,1) đến (i,j)
    vector<vector<int>> sum(m + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            sum[i][j] = sieuThi[i][j] + sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1];
        }
    }
    
    // Đếm số khu dân cư "chất lượng cao"
    int ketQua = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (banDo[i][j] == 'P') {
                // Vùng cần đếm: từ (i-d, j-d) đến (i+d, j+d)
                int r1 = max(0, i - d) + 1;
                int c1 = max(0, j - d) + 1;
                int r2 = min(m - 1, i + d) + 1;
                int c2 = min(n - 1, j + d) + 1;
                
                // Công thức prefix sum 2D: đếm số siêu thị trong vùng (r1,c1) đến (r2,c2)
                int soSieuThi = sum[r2][c2] - sum[r1-1][c2] - sum[r2][c1-1] + sum[r1-1][c1-1];
                
                if (soSieuThi >= k) {
                    ketQua++;
                }
            }
        }
    }
    
    out << ketQua;
    
    return 0;
}
