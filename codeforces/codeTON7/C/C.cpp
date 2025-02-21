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
    vii a(n); vi b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].F;
        a[i].S = i;
    }
    for (int & x : b) cin >> x;
    sort(all(a));
    sort(all(b));
    int t = 0;
    vi ans(n, -1);
    for (int i = 0; i < n; i++) {
        t += (a[i].F > b[(i + x) % n]);
        ans[a[i].S] = b[(i + x) % n];

    }
    if (t == x) {
        cout << "YES\n";
        for (int i = 0; i < n; i++) {
            cout << ans[i] << " ";
        }
        cout << "\n";
    } else cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while(T--) solve();
}
