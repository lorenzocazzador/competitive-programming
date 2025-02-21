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
    bool ans = true;
    int one = 0;
    for (int i = 0; i < n; i++) {
        one += (a[i] == 1);

        if (i > 0) {
            if (a[i] > a[i-1])
                ans &= (a[i] - a[i-1] == 1);
            else if (a[i] < a[i-1])
                ans &= (a[i] == 1);
        }
    }
    cout << (ans && (one == 1) ? "YES\n" : "NO\n");
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while(T--) solve();
}
