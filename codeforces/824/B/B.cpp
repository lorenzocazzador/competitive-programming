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
    int mn = INT_MAX;
    for (int & x : a) {
        cin >> x;
        mn = min(mn, x);
    }
    int res = 0;
    for (int & x : a) {
        int d = x / (mn * 2 - 1);
        if (x % (mn * 2 - 1) == 0) d--;
        res += d;
        if (d != 0)
            mn = min(mn, x / d);
    }
    cout << res << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while(T--) solve();
}
