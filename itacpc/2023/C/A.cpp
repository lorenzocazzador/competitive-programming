#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef vector<pii> vii;
#define F first
#define S second
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define db(x) cout << #x << ": " << x << "\n";

const ll MAXN = 1e6 + 10, MOD = 1e9 + 7;
ll fact[MAXN], inv[MAXN];

ll bin(int n, int k) { return fact[n] * inv[k] % MOD * inv[n - k] % MOD; }

ll cat(int n) {
    return bin(2 * n, n) / (n + 1);
}

int bp(ll a, ll p) {
    int res = 1;
    while (p) {
        res = p & 1 ? 1LL * res * a % MOD : res;
        a = 1LL * a * a % MOD;
        p >>= 1;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    fact[0] = 1;
    for (ll i = 1; i < MAXN; i++)
        fact[i] = fact[i - 1] * i % MOD;

    for (int i = 0; i < MAXN; i++)
        inv[i] = bp(fact[i], MOD - 2);


    int q;
    cin >> q;
    while (q--) {
        ll n, k;
        cin >> n >> k;
        ll c = cat(n);
        cout << c << "\n";
    }
}
