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
    int n, k;
    cin >> n >> k;
    vi a(n);
    for (int & x : a) cin >> x;
    int ans = 0, next = 1;
    for (int & x : a) {
        if (x != next) ans++;
        else next++;
    }
    cout << ans / k + ((ans % k) != 0) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while(T--) solve();
}
