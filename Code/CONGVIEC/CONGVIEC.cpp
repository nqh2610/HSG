// Bài 3: CONGVIEC — Sorting + DP (Weighted Job Scheduling)
#include <bits/stdc++.h>
using namespace std;

struct Job {
    int s, e;
    long long w;
};

bool cmp(const Job &a, const Job &b) {
    return a.e < b.e;
}

int main() {
    ifstream in("CONGVIEC.INP");
    ofstream out("CONGVIEC.OUT");

    int n;
    in >> n;

    vector<Job> job(n + 1);
    job[0].s = 0; job[0].e = 0; job[0].w = 0;
    for (int i = 1; i <= n; i++)
        in >> job[i].s >> job[i].e >> job[i].w;

    sort(job.begin() + 1, job.end(), cmp);

    // dp[i] = max profit considering jobs 1..i (sorted by end)
    vector<long long> dp(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        // Binary search: latest j with job[j].e <= job[i].s
        int lo = 0, hi = i - 1, best = 0;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (job[mid].e <= job[i].s) {
                best = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        dp[i] = max(dp[i - 1], job[i].w + dp[best]);
    }

    out << dp[n];

    in.close();
    out.close();
    return 0;
}
