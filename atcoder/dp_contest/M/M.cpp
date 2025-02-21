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
#define db(x) cout << #x << ": " << x << " ";

int n, k;
vi a;
const int MOD = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> k;
    a.resize(n);
    for (int & x : a) cin >> x;
    int dp[k + 1][n];
    for (int i = 0; i < n; i++) {
        dp[0][i] = 1;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= k; j++) {
            dp[j][i] = dp[j - 1][i];
            if (i > 0) {
                dp[j][i] = (dp[j][i] + dp[j][i - 1]) % MOD;
            }
        }
    }
    cout << dp[k][n - 1] << "\n";
}
