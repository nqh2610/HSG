#include <bits/stdc++.h>
using namespace std;

/*
    Bài CHEFWAR - Cuộc chiến đầu bếp
    
    Có N đầu bếp (đánh số từ 1 đến N, theo thứ tự từ trẻ đến già)
    Mỗi đầu bếp i có:
    - thich[i]: món ăn yêu thích
    - ghet[i]: món ăn ghét
    
    Bắt đầu với thực đơn P:
    - Nếu có đầu bếp ghét thực đơn hiện tại, đầu bếp TRẺ NHẤT trong số họ
      sẽ đổi thực đơn thành món họ yêu thích
    - Quá trình lặp lại cho đến khi không ai ghét nữa
    
    Output: Số lần đổi thực đơn, hoặc -1 nếu lặp vô hạn
*/

int chuyen[100005];     // chuyen[x] = món sẽ đổi thành nếu x bị ghét
bool bi_ghet[100005];   // bi_ghet[x] = true nếu có ai đó ghét món x

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ifstream cin("CHEFWAR.INP");
    ofstream cout("CHEFWAR.OUT");    
    int n, p;
    if (!(cin >> n >> p)) return 0;    
    // Đọc thông tin N đầu bếp
    for (int i = 1; i <= n; i++) {
        int thich, ghet;
        cin >> thich >> ghet;        
        // Chỉ lưu thông tin của đầu bếp ĐẦU TIÊN (trẻ nhất) ghét món này
        // Vì đầu bếp trẻ nhất sẽ thay đổi thực đơn trước
        if (!bi_ghet[ghet]) {
            chuyen[ghet] = thich;
            bi_ghet[ghet] = true;
        }
    }    
    int curr = p;   // Thực đơn hiện tại
    int dem = 0;    // Số lần đổi
    set<int> visited;   // Để phát hiện cycle    
    // Nếu thực đơn hiện tại bị ghét, tiếp tục đổi
    while (bi_ghet[curr]) {
        // Kiểm tra cycle: nếu thực đơn này đã xuất hiện trước đó → lặp vô hạn
        if (visited.count(curr)) {
            cout << -1;
            return 0;
        }
        visited.insert(curr);        
        curr = chuyen[curr];
        dem++;
    }    
    cout << dem;
    return 0;
}
