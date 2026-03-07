#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100005;
int bit[MAXN], pos[MAXN], n;
// Ham cap nhat gia tri vao BIT
void update(int idx, int val) {
    for (; idx <= n; idx += idx & -idx) bit[idx] += val;
}
// Ham tinh tong cac phan tu tu dau den idx trong BIT
int query(int idx) {
    int sum = 0;
    for (; idx > 0; idx -= idx & -idx) sum += bit[idx];
    return sum;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    ifstream cin("SAPXEP.INP");
    ofstream cout("SAPXEP.OUT");
    if (!(cin >> n)) return 0;
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        pos[x] = i;      // Luu vi tri ban dau cua gia tri x
        update(i, 1);    // Danh dau vi tri i dang co 1 phan tu
    }
    int L = 1, R = n;
    for (int i = 1; i <= n; i++) {
        if (i % 2 != 0) { // Buoc le: di chuyen gia tri nho nhat hien tai (L)
            int current_idx = query(pos[L]);
            cout << current_idx - 1 << "\n"; // So phan tu con lai ben trai no
            update(pos[L], -1);              // "Xoa" phan tu L khoi danh sach
            L++;
        } else { // Buoc chan: di chuyen gia tri lon nhat hien tai (R)
            int current_idx = query(pos[R]);
            int remaining = query(n);        // Tong so phan tu con lai hien tai
            cout << remaining - current_idx << "\n"; // So phan tu con lai ben phai no
            update(pos[R], -1);              // "Xoa" phan tu R khoi danh sach
            R--;
        }
    }
    return 0;
}
