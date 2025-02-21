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
    string s;
    cin >> n >> s;
    int ans = 0;
    vector<bool> a(n, false), b(n, false);
    for (int i = 0; i < n; i++) {
        a[i] = (s[i] == 'A');
        if (i > 0) a[i] = a[i] | a[i - 1];
    }
    for (int i = n - 1; i >= 0; i--) {
        b[i] = (s[i] == 'B');
        if (i < n - 1) b[i] = b[i] | b[i + 1];
    }
    for (int i = 0; i < n - 1; i++) {
        if (s[i] == 'A') ans += b[i];
        else ans += a[i] & b[i + 1];
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
