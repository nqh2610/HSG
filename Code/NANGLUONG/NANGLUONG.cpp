#include <bits/stdc++.h>
using namespace std;
int main() {
    // Đọc và xuất file theo tên bài trong đề
    ifstream cin("NANGLUONG.INP");
    ofstream cout("NANGLUONG.OUT");
    long long n, a, b;
    if (!(cin >> n >> a >> b)) return 0;
    // Kiểm tra xem tử số có chia hết cho mẫu số không
    if ((n * a) % (a + b) == 0) {
        long long x = (n * a) / (a + b);
        cout << x;
    } else {
        cout << -1;
    }
    return 0;
}
