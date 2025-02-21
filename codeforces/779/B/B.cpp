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

ll fact[1001];
const int MOD =  998244353;

void solve() {
    int n;
    cin >> n;
    if (n % 2)
        cout << 0 << "\n";
    else
        cout << (fact[n/2] * fact[n/2]) % MOD << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    fact[1] = 1;
    for (int i = 2; i <= 1000; i++)
        fact[i] = (fact[i-1] * i) % MOD;

    int T;
    cin >> T;
    while(T--) solve();
}
