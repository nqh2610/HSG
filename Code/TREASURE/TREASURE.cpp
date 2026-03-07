#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ifstream cin("TREASURE.INP");
    ofstream cout("TREASURE.OUT");    
    int r, c, m;
    if (!(cin >> r >> c >> m)) return 0;    
    // Đọc bản đồ
    vector<string> board(r);
    for (int i = 0; i < r; i++) {
        cin >> board[i];
    }    
    // possible[i][j] = true nếu kho báu có thể ở ô (i,j)
    vector<vector<bool>> possible;
    possible.assign(r, vector<bool>(c, false));
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (board[i][j] == '.') {
                possible[i][j] = true;
            }
        }
    }    
    string s;
    cin >> s;    
    for (char cmd : s) {
        // Tạo mảng mới, tất cả = false
        vector<vector<bool>> next_pos;
        next_pos.assign(r, vector<bool>(c, false));        
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (!possible[i][j]) continue;
                
                // Di chuyển sang phải (D)
                if (cmd == 'D' || cmd == '?') {
                    int ni = i, nj = j + 1;
                    if (nj < c && board[ni][nj] == '.')
                        next_pos[ni][nj] = true;
                }
                
                // Di chuyển sang trái (T)
                if (cmd == 'T' || cmd == '?') {
                    int ni = i, nj = j - 1;
                    if (nj >= 0 && board[ni][nj] == '.')
                        next_pos[ni][nj] = true;
                }
                
                // Di chuyển xuống dưới (N)
                if (cmd == 'N' || cmd == '?') {
                    int ni = i + 1, nj = j;
                    if (ni < r && board[ni][nj] == '.')
                        next_pos[ni][nj] = true;
                }
                
                // Di chuyển lên trên (B)
                if (cmd == 'B' || cmd == '?') {
                    int ni = i - 1, nj = j;
                    if (ni >= 0 && board[ni][nj] == '.')
                        next_pos[ni][nj] = true;
                }
            }
        }        
        // Cập nhật possible = next_pos
        possible = next_pos;
    }    
    // Đếm số vị trí có thể
    int res = 0;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (possible[i][j]) res++;
        }
    }    
    cout << res;
    return 0;
}