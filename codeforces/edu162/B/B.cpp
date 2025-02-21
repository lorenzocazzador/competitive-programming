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
    ll n, k;
    cin >> n >> k;
    vector<pair<ll,ll>> a(n);
    for (int i = 0; i < n; i++) cin >> a[i].S;
    for (int i = 0; i < n; i++) {
        cin >> a[i].F;
        a[i].F = abs(a[i].F);
    }
    sort(all(a));
    ll t = 0, b = 0;
    for (int i = 0; i < n; i++) {
        b += a[i].S;
        t = b / k + ((b % k) != 0);
        if (a[i].F < t) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while(T--) solve();
}
