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

vll get_div(ll n) {
    vll a;
    for (ll i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            a.push_back(i);
            if (n / i != i)
                a.push_back(n / i);
        }
    }
    return a;
}

vll d;
map<ll, ll> memo;
const int MOD = 1000000007;

ll dp(ll n) {
    if (n == 1)
        return 0;

    if(memo.count(n))
        return memo[n];

    ll ans = 1;
    for (ll & x : d) {
        if (x == 1) continue;
        if (n % x == 0) {
            // cout << n << " " << x << " " << tmp << "\n";
            ans = (ans + dp(n / x) % MOD) % MOD;
        }
    }

    return memo[n] = ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n;
    cin >> n;
    d = get_div(n);
    cout << dp(n);
}
