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
    ll n;
    cin >> n;
    vi squares;
    for (int i = 0; i * i < 2 * n; i++) {
        squares.push_back(i * i);
    }
    int xxor = 0;
    ll ans = n * (n + 1) / 2;
    vi cnt(2 * n, 0);
    cnt[0]++;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        xxor ^= a;
        for (int & x : squares) {
            if ((x ^ xxor) < 2 * n) {
                ans -= cnt[x ^ xxor];
            }
        }
        cnt[xxor]++;
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while(T--) solve();
}
