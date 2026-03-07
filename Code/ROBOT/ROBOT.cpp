#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ifstream cin("ROBOT.INP");
    ofstream cout("ROBOT.OUT");
    int m, n;
    if (!(cin >> m >> n)) return 0;
    string path1, path2;
    cin >> path1 >> path2;


    // Luu cac o robot 1 di qua
    set<pair<int, int>> visited1;
    int r = 1, c = 1;
    visited1.insert({r, c});
    for (char step : path1) {
        if (step == 'D') r++;
        else if (step == 'R') c++;
        visited1.insert({r, c});
    }
    // Luu cac o robot 2 di qua
    set<pair<int, int>> visited2;
    r = m; c = n;
    visited2.insert({r, c});
    for (char step : path2) {
        if (step == 'U') r--;
        else if (step == 'L') c--;
        visited2.insert({r, c});
    }
    // Dem so o chung
    int res = 0;
    for (auto cell : visited2) {
        if (visited1.count(cell)) {
            res++;
        }
    }
    cout << res;
    return 0;
}
