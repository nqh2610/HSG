/*
    Bai 3: TIEPSUC - Tiep suc (HSG12_2026)
    N tram dung chan ket noi thanh cay
    N-1 VDV: VDV i chay tu tram i den tram i+1
    Moi VDV di qua tram nao thi tram do nhan 1 chai nuoc
    Tim so chai nuoc tai moi tram
*/

#include <bits/stdc++.h>
using namespace std;


vector<vector<int>> ke;     // Danh sach ke
vector<int> Trace;          // Truy vet duong di
vector<bool> Free;          // Danh dau da tham
vector<long long> chai;     // So chai nuoc tai moi tram
int n;


ifstream in("TIEPSUC.INP");
ofstream out("TIEPSUC.OUT");


// BFS tim duong tu S den F
void BFS(int S, int F) {
    Free.assign(n + 1, true);
    Trace.assign(n + 1, -1);
    
    queue<int> q;
    q.push(S);
    Free[S] = false;
    Trace[S] = S;
    
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        
        if (u == F) break;
        
        for (int v : ke[u]) {
            if (Free[v]) {
                Free[v] = false;
                Trace[v] = u;
                q.push(v);
            }
        }
    }
}


// Truy vet va dem chai nuoc
void DemChai(int S, int F) {
    int cur = F;
    while (cur != S) {
        chai[cur]++;
        cur = Trace[cur];
    }
    chai[S]++;
}


void Input() {
    in >> n;
    ke.assign(n + 1, vector<int>());
    chai.assign(n + 1, 0);
    
    int u, v;
    for (int i = 0; i < n - 1; i++) {
        in >> u >> v;
        ke[u].push_back(v);
        ke[v].push_back(u);
    }
}


void Solve() {
    // VDV i chay tu tram i den tram i+1
    for (int i = 1; i < n; i++) {
        BFS(i, i + 1);
        DemChai(i, i + 1);
    }
}


void Output() {
    for (int i = 1; i <= n; i++) {
        out << chai[i];
        if (i < n) out << " ";
    }
}


int main() {
    Input();
    Solve();
    Output();
    return 0;
}
