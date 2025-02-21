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
    int n;
    cin >> n;
    vi a(n);
    for (int & x : a) cin >> x;
    sort(all(a));
    map<int, vi> m;
    vector<vi> div(n);
    int mx = 0;
    for (int j = 0; j < n - 1; j++) {
        int x = a[j];
        for (int i = 1; i * i <= x; i++) {
            if (x % i == 0) {
                m[i].push_back(j);
                if (x / i != i)
                    m[x / i].push_back(j);
                mx = max({mx, i, x / i});
            }
        }
    }
    vll cnt(mx + 1, 0);
    for (int i = mx; i >= 1; i--) {
        for (int j = 1; j < sz(m[i]); j++) {
            cnt[i] += (ll)j * (n - m[i][j] - 1);
        }
        for (int j = 2; i * j <= mx; j++) {
            cnt[i] -= cnt[i * j];
        }
    }
    ll ans = 0;
    for (int i = 1; i <= mx; i++) {
        ans += cnt[i] * i;
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
