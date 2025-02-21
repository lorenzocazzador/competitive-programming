#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;
    long long m = 0, p = 0;
    for (char & c : s) {
        m += c == '-';
        p += c == '+';
    }
    int q;
    cin >> q;
    while (q--) {
        long long a, b;
        cin >> a >> b;
        if (p == m) {
            cout << "YES\n";
        } else if (a == b) {
            cout << "NO\n";
        } else if ((b * (m - p)) % (a - b)) {
            cout << "NO\n";
        } else {
            long long r = b * (m - p) / (a - b);
            cout << (-m <= r && r <= p ? "YES" : "NO") << "\n";
        }
    }
}
