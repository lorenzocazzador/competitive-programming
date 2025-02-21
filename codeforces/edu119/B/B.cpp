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

void solve() {
    ll w, h;
    cin >> w >> h;
    ll res = 0;
    for (int i = 0; i < 4; i++) {
        int k; cin >> k;
        vll v(k);
        for (ll & x : v) cin >> x;
        if (i < 2)
            res = max(res, (v[k-1]-v[0]) * h);
        else
            res = max(res, (v[k-1]-v[0]) * w);
    }
    cout << res << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while(T--) solve();
}
