#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> v(n + 2, 0);
        v[n + 1] = 1440;
        for (int i = 1; i <= n; i++) cin >> v[i];
        int c = 0;
        for (int i = 1; i < n + 2; i++) {
            c += (v[i] - v[i - 1]) / 120;
        }
        cout << (c >= 2 ? "YES\n" : "NO\n");
    }
}
