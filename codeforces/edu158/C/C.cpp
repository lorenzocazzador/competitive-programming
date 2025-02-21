#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
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
    int mn = INT_MAX, mx = 0;
    for (int &x : a) {
        cin >> x;
        mn = min(mn, x);
        mx = max(mx, x);
    }
    int res = (mx == mn ? 0 : log2(mx - mn) + 1);
    cout << res << "\n";
    if (res <= n && res > 0) {
        for (int i = 0; i < res; i++) {
            cout << mn % 2 << " ";
            mn = (mn + (mn % 2)) / 2;
        }
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--)
        solve();
}
