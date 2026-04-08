// Bài 1: NGOAC — Stack O(N)
#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream in("NGOAC.INP");
    ofstream out("NGOAC.OUT");

    string s;
    in >> s;
    int n = s.size();

    stack<int> st;
    st.push(-1); // sentinel
    int ans = 0;

    for (int i = 0; i < n; i++) {
        if (s[i] == '(') {
            st.push(i);
        } else {
            st.pop();
            if (st.empty()) {
                st.push(i); // new sentinel
            } else {
                ans = max(ans, i - st.top());
            }
        }
    }

    out << ans;

    in.close();
    out.close();
    return 0;
}
