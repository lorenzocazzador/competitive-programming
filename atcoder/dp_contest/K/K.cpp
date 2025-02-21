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

    int n, k;
    cin >> n >> k;
    vi a(n);
    for (int & x : a) cin >> x;
    int dp[k + 1][2];
    for (int i = 0; i <= k; i++) {
        dp[i][0] = dp[i][1] = -1;
    }
    dp[0][0] = 1;
    dp[0][1] = 0;
    for (int i = 1; i <= k; i++) {
        for (int j = 0; j < 2; j++) {
            dp[i][j] = (j + 1) % 2;
            for (int z = 0; z < n && a[z] <= i; z++) {
                if (dp[i - a[z]][(j + 1) % 2] == j) {
                    dp[i][j] = j;
                    break;
                }
            }
        }
    }

    cout << (dp[k][0] == 0 ? "First" : "Second") << "\n";
}
