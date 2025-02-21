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

int n, l, p, d;
vector<vector<int>> m;
vector<int> dp;
vector<bool> vis;
const int MOD = 1000000007;

int visit(int k) {
    if (vis[k]) {
        return dp[k];
    }
    vis[k] = true;
    for (int & x : m[k]) {
        if (x >= l) {
            dp[k] = (dp[k] + 1) % MOD;
            vis[x] = true;
        } else {
            dp[k] = (dp[k] + visit(x)) % MOD;
        }
    }
    return dp[k];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> l;
    m.resize(l);
    for (int i = 0; i < l; i++) {
        int k;
        cin >> k;
        m[i].resize(k);
        for (int j = 0; j < k; j++) {
            cin >> m[i][j];
            m[i][j]--;
        }
    }
    dp.resize(n, 0);
    vis.resize(n, false);
    visit(0);
    for (int i = l; i < n; i++) d += vis[i];
    cout << dp[0] << " " << d << "\n";
}
