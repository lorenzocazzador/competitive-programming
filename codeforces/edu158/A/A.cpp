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
    int n, x;
    cin >> n >> x;
    vi a(n);
    for (int & x : a) cin >> x;
    int ans = a[0];
    for (int i = 1; i < n; i++) ans = max(ans, a[i] - a[i - 1]);
    ans = max(ans, (x - a[n - 1]) * 2);
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while(T--) solve();
}
