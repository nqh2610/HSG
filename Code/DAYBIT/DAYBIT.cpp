#include <bits/stdc++.h>
using namespace std;

int a[5001];
int lis[5001], lds[5001];

int main() {
    ifstream in("DAYBIT.INP");
    ofstream out("DAYBIT.OUT");

    int n;
    in >> n;
    for (int i = 0; i < n; i++) in >> a[i];

    // LIS ending at i (from left)
    for (int i = 0; i < n; i++) {
        lis[i] = 1;
        for (int j = 0; j < i; j++)
            if (a[j] < a[i])
                lis[i] = max(lis[i], lis[j] + 1);
    }

    // LDS starting at i (from right)
    for (int i = n - 1; i >= 0; i--) {
        lds[i] = 1;
        for (int j = i + 1; j < n; j++)
            if (a[j] < a[i])
                lds[i] = max(lds[i], lds[j] + 1);
    }

    int ans = 1;
    for (int i = 0; i < n; i++)
        ans = max(ans, lis[i] + lds[i] - 1);

    out << ans;

    in.close();
    out.close();
    return 0;
}
