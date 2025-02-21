#include <bits/stdc++.h>
using namespace std;

vector<int> solve() {
    int n[4];
    cin >> n[0] >> n[1] >> n[2] >> n[3];
    int m;
    cin >> m;
    string f[4];
    cin >> f[0] >> f[1] >> f[2] >> f[3];
    for (int i = 0; i <= n[0] - m; i++) {
        string a = f[0].substr(i, m);
        for (int j = 0; j <= n[1] - m; j++) {
            string b = f[1].substr(j, m);
            for (int k = 0; k <= n[2] - m; k++) {
                string c = f[2].substr(k, m);
                for (int z = 0; z <= n[3] - m; z++) {
                    string d = f[3].substr(z, m);
                    if (a == b && b == c && c == d)
                        return {i, j, k, z};
                }
            }
        }
    }
}

int main() {
    int t;
    cin >> t;
    for (int nt = 1; nt <= t; nt++) {
        cout << "Case #" << nt << ": ";
        for (int x : solve()) {
            cout << x << " ";
        }
        cout << "\n";
    }
}
