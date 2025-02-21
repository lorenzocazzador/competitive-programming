#include <bits/stdc++.h>
using namespace std;

int n, m, v[1010], g[1010], mem[1010][1010];

int dp(int iv, int ig) {
    if (iv == n) {
        return 0;
    }
    if (mem[iv][ig] != -1) {
        return mem[iv][ig];
    }
    int res = 1 + dp(iv + 1, ig);
    if (ig < m) {
        res = max(res, dp(iv, ig + 1));
    }
    if (ig < m && v[iv] < g[ig]) {
        res = max(res, 2 + dp(iv + 1, ig + 1));
    }
    return mem[iv][ig] = res;
}

int solve() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> g[i];
    }
    memset(mem, -1, sizeof mem);
    return dp(0, 0);
}

int main() {
    int t;
    cin >> t;
    for (int nt = 1; nt <= t; nt++) {
        cout << "Case #" << nt << ": " << solve() << "\n";
    }
}
