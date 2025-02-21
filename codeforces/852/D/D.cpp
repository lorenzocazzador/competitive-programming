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

ll sum(ll n) {
    return n * (n + 1) / 2;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vll p(n), q(n), a(n + 1), b(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        a[p[i]] = i;
    }
    for (int i = 0; i < n; i++) {
        cin >> q[i];
        b[q[i]] = i;
    }
    ll l = min(a[1], b[1]), r = max(a[1], b[1]), i = 2;
    ll ans = sum(l) + sum(n - r - 1) + sum(r - l - 1) + 1;
    while (i <= n) {
        ll c, d;
        bool flag = true;
        if (max(a[i], b[i]) < l) {
            c = max(a[i], b[i]);
            d = n;
        } else if (min(a[i], b[i]) > r) {
            c = -1;
            d = min(a[i], b[i]);
        } else if (a[i] < l && b[i] > r) {
            c = a[i];
            d = b[i];
        } else if (b[i] < l && a[i] > r) {
            c = b[i];
            d = a[i];
        } else flag = false;
        if (flag) {
            ans += (l - c) * (d - r);
        }
        l = min({l, a[i], b[i]});
        r = max({r, a[i], b[i]});
        i++;
    }
    cout << ans << "\n";
}
