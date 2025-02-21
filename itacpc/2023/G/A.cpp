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

ll x, y, tx, ty, wx, wy;

ll get_pos_line(ll xx, ll yy) {
    assert(xx == 0 || xx == x || yy == 0 || yy == y);
    ll pos = 0;
    if (xx == 0)
        pos = yy;
    else if (xx == x)
        pos = y + x + (y - yy);
    else if (yy == 0)
        pos = y * 2 + x + (x - xx);
    else if (yy == y)
        pos = y + xx;
    return pos;
}

ll train(ll xx, ll yy) {
    assert(xx == 0 || xx == x || yy == 0 || yy == y);
    ll p = x * 2 + y * 2;
    // if (xx == tx) {
    //     ll d = yy - ty;
    //     if (tx == 0) {
    //         return (ty <= yy ? d : p - d);
    //     } else {
    //         return (ty >= yy ? -d : p + d);
    //     }
    // } else if (yy == ty) {
    //     ll d = xx - tx;
    //     if (ty == 0) {
    //         return (xx <= tx ? -d : p + d);
    //     } else {
    //         return (xx >= tx ? d : p - d);
    //     }
    // } else return LLONG_MAX;
    ll pos_t = get_pos_line(tx, ty);
    ll pos = get_pos_line(xx, yy);
    if (pos >= pos_t) return pos - pos_t;
    else return p - (pos_t - pos);
}

void solve() {
    cin >> x >> y >> tx >> ty >> wx >> wy;
    ll ans = LLONG_MAX;
    // left
    ll t = train(0, wy);
    assert(t != LLONG_MAX);
    ll f = wx;
    if (t >= f) ans = min(ans, t);
    // right
    t = train(x, wy);
    assert(t != LLONG_MAX);
    f = x - wx;
    if (t >= f) ans = min(ans, t);
    // up
    t = train(wx, y);
    assert(t != LLONG_MAX);
    f = y - wy;
    if (t >= f) ans = min(ans, t);
    // down
    t = train(wx, 0);
    assert(t != LLONG_MAX);
    f = wy;
    if (t >= f) ans = min(ans, t);

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) solve();
}
