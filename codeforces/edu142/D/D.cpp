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

int get_res(vi & a, vi & b) {
    int i = 0;
    while (i < sz(a) && a[i] == b[i]) {
        i++;
    }
    return i;
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vi> a(n, vi(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            a[i][j]--;
        }
    }
    vector<vi> b(n, vi(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            b[i][a[i][j]] = j;
        }
    }
    sort(all(b));
    for (int i = 0; i < n; i++) {
        int x = lower_bound(all(b), a[i]) - b.begin();
        int ans = 0;
        if (x > 0) ans = max(ans, get_res(a[i], b[x - 1]));
        if (x < n) ans = max(ans, get_res(a[i], b[x]));
        cout << ans << " ";
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while(T--) solve();
}
