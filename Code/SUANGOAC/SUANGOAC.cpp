// Bai 3: SUANGOAC — Greedy O(N)
#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream in("SUANGOAC.INP");
    ofstream out("SUANGOAC.OUT");

    string s;
    in >> s;

    int open = 0, add = 0;
    for (char c : s) {
        if (c == '(') open++;
        else {
            if (open > 0) open--;
            else add++;
        }
    }

    out << open + add;

    in.close();
    out.close();
    return 0;
}
