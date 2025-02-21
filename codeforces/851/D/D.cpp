#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int,int> pii;
typedef vector<pii> vii;
#define F first
#define S second
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define db(x) cout << #x << ": " << x << "\n";

const int MOD = 1000000007;

ll bin_pow(ll a, ll b) {
    a %= MOD;
    ll res = 1;
    while (b > 0) {
        if (b & 1) {
            res = res * a % MOD;
        }
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vi a(n);
    for (int & x : a) cin >> x;
    ll res = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int l = lower_bound(all(a), 2 * a[i] - a[j]) - a.begin();
            int r = lower_bound(all(a), 2 * a[j] - a[i]) - a.begin();
            res = (res + bin_pow(2, l + n - r)) % MOD;
        }
    }
    cout << res << "\n";
}
