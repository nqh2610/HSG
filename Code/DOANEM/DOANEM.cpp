#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream in("DOANEM.INP");
    ofstream out("DOANEM.OUT");

    int n;
    long long K;
    in >> n >> K;
    vector<long long> a(n);
    for(int i = 0; i < n; i++) in >> a[i];

    // Two pointers + 2 monotonic deques
    deque<int> dqMax, dqMin;
    long long ans = 0;
    int l = 0;

    for(int r = 0; r < n; r++) {
        while(!dqMax.empty() && a[dqMax.back()] <= a[r]) dqMax.pop_back();
        dqMax.push_back(r);
        while(!dqMin.empty() && a[dqMin.back()] >= a[r]) dqMin.pop_back();
        dqMin.push_back(r);

        while(a[dqMax.front()] - a[dqMin.front()] > K) {
            l++;
            if(dqMax.front() < l) dqMax.pop_front();
            if(dqMin.front() < l) dqMin.pop_front();
        }

        ans += r - l + 1;
    }

    out << ans;
    in.close();
    out.close();
    return 0;
}
