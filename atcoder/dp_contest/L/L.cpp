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

int n;
vi a;
bool calc[3005][3005][2];
ll dp[3005][3005][2];

ll f(int l, int r, bool t) {
    if (l > r) {
        return 0;
    }
    if (calc[l][r][t]) {
        return dp[l][r][t];
    }
    ll r1 = f(l + 1, r, !t), r2 = f(l, r - 1, !t), res;
    if (t) {
        res = max(r1 + a[l], r2 + a[r]);
    } else {
        res = min(r1 - a[l], r2 - a[r]);
    }
    calc[l][r][t] = true;
    return dp[l][r][t] = res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    a.resize(n);
    for (int & x : a) cin >> x;
    cout << f(0, n - 1, true) << "\n";
}
