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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    char g[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> g[i][j];
        }
    }
    int dp[n][m], ans = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i > 0 && j > 0 && g[i][j] == g[i][j - 1] && g[i - 1][j] == g[i - 1][j - 1]) {
                dp[i][j] = min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]}) + 1;
            } else {
                dp[i][j] = 1;
            }
            ans = max(ans, dp[i][j]);
        }
    }
    cout << ans * ans << "\n";
}
