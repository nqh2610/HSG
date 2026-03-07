/*
    Bai 3: TIEPSUC - Tiep suc (HSG12_2026)
    DFS tim duong di tren cay
*/

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> ke;
vector<int> Trace;
vector<bool> Free;
int n;

ifstream in("TIEPSUC.INP");
ofstream out("TIEPSUC.OUT");

void DFS(int S) {
    stack<int> stk;
    stk.push(S);
    Free[S] = false;
    
    while (!stk.empty()) {
        int u = stk.top();
        stk.pop();
        
        for (int v : ke[u]) {
            if (Free[v]) {
                Free[v] = false;
                Trace[v] = u;
                stk.push(v);
            }
        }
    }
}

int main() {
    in >> n;
    
    ke.assign(n + 1, vector<int>());
    
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        in >> u >> v;
        ke[u].push_back(v);
        ke[v].push_back(u);
    }
    
    vector<long long> chai(n + 1, 0);
    
    // VDV i chay tu tram i den tram i+1
    for (int i = 1; i < n; i++) {
        int S = i, F = i + 1;
        
        Free.assign(n + 1, true);
        Trace.assign(n + 1, -1);
        
        DFS(S);
        
        // Truy vet duong di tu F ve S
        int cur = F;
        while (cur != S) {
            chai[cur]++;
            cur = Trace[cur];
        }
        chai[S]++;
    }
    
    for (int i = 1; i <= n; i++) {
        out << chai[i];
        if (i < n) out << " ";
    }
    
    return 0;
}
