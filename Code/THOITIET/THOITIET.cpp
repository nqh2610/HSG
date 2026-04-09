// Bai 1: THOITIET — Monotonic Stack O(N)
#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream in("THOITIET.INP");
    ofstream out("THOITIET.OUT");

    int n;
    in >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) in >> a[i];

    vector<int> ans(n, 0);
    stack<int> st;
    for (int i = 0; i < n; i++) {
        while (!st.empty() && a[i] > a[st.top()]) {
            ans[st.top()] = i - st.top();
            st.pop();
        }
        st.push(i);
    }

    for (int i = 0; i < n; i++) {
        if (i) out << " ";
        out << ans[i];
    }

    in.close();
    out.close();
    return 0;
}
