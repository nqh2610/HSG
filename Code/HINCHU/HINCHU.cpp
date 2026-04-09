// Bai 1: HINCHU — Largest Rectangle in Histogram, Monotone Stack O(N)
#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream in("HINCHU.INP");
    ofstream out("HINCHU.OUT");

    int n;
    in >> n;
    vector<int> h(n);
    for (int i = 0; i < n; i++) in >> h[i];

    stack<int> st;
    long long ans = 0;

    for (int i = 0; i <= n; i++) {
        int cur = (i == n) ? 0 : h[i];
        while (!st.empty() && h[st.top()] > cur) {
            long long height = h[st.top()]; st.pop();
            long long width = st.empty() ? i : i - st.top() - 1;
            ans = max(ans, height * width);
        }
        st.push(i);
    }

    out << ans;

    in.close();
    out.close();
    return 0;
}
