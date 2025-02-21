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
    ll n, x;
    cin >> n >> x;
    vll a(n);
    map<ll, ll> occ;
    for (ll & x : a) {
        cin >> x;
        occ[x]++;
    }
    sort(all(a));
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ll v = a[i];
        if (occ[v] > 0) {
            occ[v]--;
            if (occ[v * x] > 0) {
                occ[v * x]--;
            } else ans++;
        }
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while(T--) solve();
}
