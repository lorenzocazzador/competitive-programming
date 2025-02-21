#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<array<int, 2>> e(m);
        vector<int> deg(n + 1, 0);
        for (int i = 0; i < m; i++) {
            cin >> e[i][0] >> e[i][1];
            deg[e[i][0]]++;
            deg[e[i][1]]++;
        }
        if (m == n * (n - 1) / 2) {
            // complete graph
            cout << "3\n";
            bool flag = true;
            for (auto & x : e) {
                if (x[0] == 1 || x[1] == 1) {
                    cout << (flag ? 1 : 2) << " ";
                    flag = false;
                } else cout << 3 << " ";
            }
            cout << "\n";
        } else {
            int z = 1;
            while (z <= n && deg[z] == n - 1) z++;
            cout << 2 << "\n";
            for (auto & x : e) {
                cout << (x[0] == z || x[1] == z ? 1 : 2) << " ";
            }
            cout << "\n";
        }
    }
}
