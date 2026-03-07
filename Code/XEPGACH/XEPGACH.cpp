#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ifstream cin("XEPGACH.INP");
    ofstream cout("XEPGACH.OUT");
    int n;
    if (!(cin >> n)) return 0;
    long long h_truoc = 0, h_nay;
    long long buoc = 0;
    for (int i = 0; i < n; i++) {
        cin >> h_nay;
        // Neu o hien tai cao hon o truoc, chung ta can 1 buoc xep moi
        if (h_nay > h_truoc) {
            buoc++;
        }
        h_truoc = h_nay;
    }
    cout << buoc;
    return 0;
}

