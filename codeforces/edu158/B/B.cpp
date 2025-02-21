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
    vi c(n + 1);
    c[0] = 1;
    for (int i = 1; i <= n; i++) cin >> c[i];
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += max(0, c[i] - c[i - 1]);
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
