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
    int n, m;
    cin >> n >> m;
    vi a(n, 1), b(n);
    for (int i = 1; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    sort(all(a));
    sort(all(b));
    int ans = 0;
    for (int j = 0, i = 0; j < n; j++) {
        if (a[i] < b[j]) {
            i++;
        } else {
            ans++;
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
