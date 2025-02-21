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
    bool s = is_sorted(all(a));
    if (n < 3 || s)
        cout << (s ? "YES" : "NO") << "\n";
    else {
        vi b = a;
        sort(all(b));
        for (int i = 0; i < n-1; i++)
            if (b[i] == b[i+1]) {
                cout << "YES\n";
                return;
            }
        map<int,int> m;
        for (int i = 0; i < n; i++)
            m[a[i]] = i;
        for (int i = 0; i < n - 3; i++) {
            // cycle i, i+1, m[b[i]]
            int x = m[b[i]];
            int y = x != i+1 ? i+1 : i+2;
            a[x] = a[y]; m[a[y]] = x;
            a[y] = a[i]; m[a[i]] = y;
            a[i] = b[i]; m[i] = i;
            assert(a[i] == b[i]);
        }
        int c = 0;
        for (int i = 0; i < 3; i++)
            c += a[n-3+i] != b[n-3+i];
        cout << (c == 3 || c == 0 ? "YES" : "NO") << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while(T--) solve();
}
