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

const int MOD = 1000000007;

ll sum_square(ll x) {
    return (((x * (x + 1)) % MOD) * (((2*x) % MOD) + 1)) % MOD;
}

ll sum(ll x) {
    return (((x * ((x + 1) % MOD)) % MOD) * 3) % MOD;
}

void solve() {
    int n;
    cin >> n;
    cout << ( ((((sum_square(n-1) + sum(n-1)) % MOD) + sum_square(n)) % MOD) * 337) % MOD << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while(T--) solve();
}
