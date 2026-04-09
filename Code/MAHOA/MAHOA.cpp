// Bai 1: MAHOA — String RLE decode, find char at position K
#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream in("MAHOA.INP");
    ofstream out("MAHOA.OUT");

    string s;
    long long k;
    in >> s >> k;

    int i = 0;
    long long pos = 0;
    while (i < (int)s.size()) {
        char ch = s[i];
        i++;
        long long num = 0;
        while (i < (int)s.size() && s[i] >= '0' && s[i] <= '9') {
            num = num * 10 + (s[i] - '0');
            i++;
        }
        if (num == 0) num = 1;
        if (pos + num >= k) {
            out << ch;
            in.close();
            out.close();
            return 0;
        }
        pos += num;
    }

    in.close();
    out.close();
    return 0;
}
