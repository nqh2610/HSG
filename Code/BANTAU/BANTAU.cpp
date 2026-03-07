#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;

/*
    Bài BANTAU - Bắn tàu (HSG12 2022-2023)
    
    1. Ý tưởng:
    - Chia N tàu thành tối đa (K+1) nhóm liên tiếp
    - Mỗi nhóm dùng mức năng lượng = khoảng cách tàu xa nhất trong nhóm
    - Điểm phạt nhóm = (Mức năng lượng * Số tàu) - (Tổng khoảng cách)
    
    2. Quy hoạch động:
    - dp[i][k] = điểm phạt ít nhất khi xử lý i tàu với k lần đổi năng lượng
    - Điều kiện biên: dp[i][0] = max(1..i) * i - sum(1..i)
    - Chuyển trạng thái: dp[i][k] = min(dp[j][k-1] + cost(j+1,i)), j từ k đến i-1
    - Kết quả: min(dp[n][k]) với k từ 0 đến K
    
    3. Độ phức tạp: O(K * N^2) với N = 400 → chạy tốt
*/

ll d[405];               // Khoảng cách tàu i
ll pref[405];            // Tổng tiền tố
ll dp[405][405];         // dp[i][k]
ll max_val[405][405];    // max_val[i][j] = max(d[i..j])

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    ifstream cin("BANTAU.INP");
    ofstream cout("BANTAU.OUT");
    
    int n, K;
    if (!(cin >> n >> K)) return 0;
    
    // Đọc dữ liệu và tính prefix sum
    for (int i = 1; i <= n; i++) {
        cin >> d[i];
        pref[i] = pref[i - 1] + d[i];
    }
    
    // Tiền xử lý max trong đoạn [i, j]
    for (int i = 1; i <= n; i++) {
        max_val[i][i] = d[i];
        for (int j = i + 1; j <= n; j++)
            max_val[i][j] = max(max_val[i][j - 1], d[j]);
    }

    // Khởi tạo dp với vô cùng
    for (int i = 0; i <= n; i++)
        for (int k = 0; k <= K; k++) 
            dp[i][k] = INF;
    
    // Điều kiện biên: k=0 (chỉ dùng 1 mức năng lượng cho i tàu đầu)
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++) {
        dp[i][0] = max_val[1][i] * i - pref[i];
    }
    
    // Chuyển trạng thái: dp[i][k] = min(dp[j][k-1] + cost(j+1, i))
    // j chạy từ k đến i-1 (cần ít nhất k tàu để có k lần đổi)
    for (int k = 1; k <= K; k++) {
        for (int i = k + 1; i <= n; i++) {  // Cần ít nhất k+1 tàu cho k lần đổi
            for (int j = k; j < i; j++) {   // j từ k đến i-1
                if (dp[j][k - 1] == INF) continue;
                ll cost = max_val[j + 1][i] * (i - j) - (pref[i] - pref[j]);
                dp[i][k] = min(dp[i][k], dp[j][k - 1] + cost);
            }
        }
    }
    
    // Tìm kết quả: min(dp[n][k]) với k từ 0 đến K
    ll ans = INF;
    for (int k = 0; k <= K; k++) 
        ans = min(ans, dp[n][k]);
    
    cout << ans;
    return 0;
}
