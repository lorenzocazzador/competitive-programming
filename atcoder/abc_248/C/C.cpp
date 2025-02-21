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

int N, M, K;
const int MOD = 998244353, MAXN = 51;

int memo[MAXN][MAXN*MAXN];

int solve(int i, int sum) {
    if (i == N) {
        return 1;
    }
    if (memo[i][sum] != -1) {
        return memo[i][sum];
    }

    int res = 0;
    for (int j = 1; j <= min(M, sum); j++)
        res = (res + solve(i + 1, sum - j)) % MOD;
    return memo[i][sum] = res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M >> K;
    memset(memo, -1, sizeof(memo));
    cout << solve(0, K) << "\n";
}
