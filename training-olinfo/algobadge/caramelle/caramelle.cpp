#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll gcd (ll a, ll b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

ll lcm(ll a, ll b) {
    return a * b / gcd(a, b);
}

int main() {
    int t;
    cin >> t;
    for (int nt = 1; nt <= t; nt++) {
        int n;
        cin >> n;
        ll res = 1;
        for (int i = 0; i < n; i++) {
            ll x;
            cin >> x;
            res = lcm(res, x);
        }
        cout << "Case #" << nt << ": " << res << "\n";
    }
}
