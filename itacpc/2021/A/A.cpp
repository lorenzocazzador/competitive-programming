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

vll num, _xor, a;
const int N_BITS = 22;

ll findRes() {
    ll res = 0;
    for (ll i = 0; i < N_BITS; i++) {
        if (_xor[i] != 0)
            res = max(res, num[i]);
        else
            res = max(res, num[i] - 1);
    }
    return res;
}

void update(ll &pos, ll &y) {
    ll x = a[pos-1];
    for (ll i = 0; i < N_BITS; i++) {
        if (x & (1LL << i)) {
            num[i]--;
            _xor[i] ^= x;
        }
    }

    x = y;
    a[pos-1] = y;
    for (ll i = 0; i < N_BITS; i++) {
        if (x & (1LL << i)) {
            num[i]++;
            _xor[i] ^= x;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n, q;
    cin >> n >> q;
    a.resize(n);
    for (ll & x : a) cin >> x;
    num.resize(N_BITS, 0);
    _xor.resize(N_BITS, 0);
    for (ll & x : a) {
        for (ll i = 0; i < N_BITS; i++) {
            if (x & (1LL << i)) {
                num[i]++;
                _xor[i] ^= x;
            }

        }
    }
    cout << findRes() << "\n";
    while (q--) {
        ll pos, x;
        cin >> pos >> x;
        update(pos, x);
        cout << findRes() << "\n";
    }
}
