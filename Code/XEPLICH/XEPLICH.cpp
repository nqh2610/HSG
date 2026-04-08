// Bai 2: XEPLICH — Greedy (Sort by value + Set) O(N log N)
#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream in("XEPLICH.INP");
    ofstream out("XEPLICH.OUT");

    int n;
    in >> n;

    vector<pair<long long, int> > jobs(n);
    int maxD = 0;
    for (int i = 0; i < n; i++) {
        in >> jobs[i].second >> jobs[i].first; // deadline, value
        maxD = max(maxD, jobs[i].second);
    }

    sort(jobs.begin(), jobs.end(), greater<pair<long long, int> >());

    set<int> avail;
    for (int d = 1; d <= maxD; d++) avail.insert(d);

    long long total = 0;
    for (int i = 0; i < n; i++) {
        int d = jobs[i].second;
        long long v = jobs[i].first;
        set<int>::iterator it = avail.upper_bound(d);
        if (it != avail.begin()) {
            --it;
            total += v;
            avail.erase(it);
        }
    }

    out << total;

    in.close();
    out.close();
    return 0;
}
