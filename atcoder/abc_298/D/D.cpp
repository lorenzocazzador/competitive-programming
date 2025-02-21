#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define sz(s) (int)s.size()

const int MOD = 998244353;

int main() {
    ll n = 1, q;
    string s = "1";
    cin >> q;
    vector<ll> pot10(q + 1, 1);
    for (int i = 1; i <= q; i++) {
        pot10[i] = pot10[i - 1] * 10 % MOD;
    }
    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            ll x;
            cin >> x;
            s += to_string(x);
            n = ((n * 10) % MOD + x) % MOD;
        } else if (t == 2) {
            ll c = s[0] - '0';
            n = (n - (c * pot10[sz(s) - 1] % MOD) + MOD) % MOD;
            s.erase(s.begin());
        } else {
            cout << n << "\n";
        }
    }
}
