/*
    Câu 4: CONGTY - Công ty (3 điểm)
    
    ĐỀ BÀI: Công ty N người, cây phân cấp gốc tại 1.
            Chọn nhiều người nhất trong cây con của u sao cho không có 
            2 người x, y cùng được chọn với x quản lý y và lương[x] <= lương[y].
    
    Ý TƯỞNG:
    - Duyệt cây từ lá lên gốc (dùng stack thay vì đệ quy để tránh tràn bộ nhớ)
    - Với mỗi người v, tính 2 trường hợp:
      + Không chọn v: cộng kết quả của tất cả cấp dưới
      + Chọn v: được 1 người, cấp dưới chỉ được chọn nếu lương < lương[v]
    - Lấy max của 2 trường hợp
    - Rút gọn các mức lương thành số nhỏ để tính nhanh hơn
    
    Độ phức tạp: O(N * số mức lương khác nhau)
*/

#include <bits/stdc++.h>
using namespace std;

int n, q;
vector<int> luong;
vector<vector<int>> con;
vector<int> thuTu;       // thứ tự duyệt từ lá lên gốc
vector<int> nenLuong;    // giá trị lương sau khi nén
int soLuong;             // số giá trị lương khác nhau

ifstream in("CONGTY.INP");
ofstream out("CONGTY.OUT");

// DFS dùng stack để tìm thứ tự post-order
void DFS_ThuTu(int root) {
    stack<pair<int, bool>> stk;
    stk.push({root, false});
    
    while (!stk.empty()) {
        int v = stk.top().first;
        bool daXuLyCon = stk.top().second;
        stk.pop();
        
        if (daXuLyCon) {
            thuTu.push_back(v);
        } else {
            stk.push({v, true});
            for (int u : con[v]) {
                stk.push({u, false});
            }
        }
    }
}

// Tính số người tối đa trong cây con gốc root
int TinhKetQua(int root) {
    thuTu.clear();
    DFS_ThuTu(root);
    
    // dp[v][l] = số người tối đa trong cây con v, với giới hạn lương là nenLuong[l]
    // l = 0 nghĩa là không có giới hạn (có thể chọn bất kỳ)    
    map<int, vector<int>> dp;
    
    for (int v : thuTu) {
        dp[v].assign(soLuong + 1, 0);
        
        for (int l = 0; l <= soLuong; l++) {
            // Trường hợp KHÔNG chọn v
            int khongChon = 0;
            for (int u : con[v]) {
                khongChon += dp[u][l];
            }
            
            // Trường hợp CHỌN v
            int chon = 0;
            // Chỉ được chọn nếu lương[v] < giới hạn (hoặc không có giới hạn)
            if (l == 0 || luong[v] < nenLuong[l]) {
                chon = 1;
                // Tìm mức lương của v sau khi nén
                int lv = lower_bound(nenLuong.begin() + 1, nenLuong.end(), luong[v]) - nenLuong.begin();
                for (int u : con[v]) {
                    chon += dp[u][lv];
                }
            }
            
            dp[v][l] = max(khongChon, chon);
        }
    }
    
    return dp[root][0];
}

int main() {
    in >> n >> q;
    
    luong.resize(n + 1);
    con.resize(n + 1);
    
    // loại bỏ các mức lương trùng nhau
    set<int> tapLuong;
    for (int i = 1; i <= n; i++) {
        in >> luong[i];
        tapLuong.insert(luong[i]);
    }
    
    // Nén lương
    nenLuong.push_back(0); // index 0 không dùng
    for (int x : tapLuong) {
        nenLuong.push_back(x);
    }
    soLuong = nenLuong.size() - 1;
    
    // Đọc cấp trên của người 2, 3, ..., n
    for (int i = 2; i <= n; i++) {
        int capTren;
        in >> capTren;
        con[capTren].push_back(i);
    }
    
    // Xử lý Q truy vấn
    while (q--) {
        int u;
        in >> u;
        out << TinhKetQua(u) << "\n";
    }
    
    return 0;
}
