#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef vector<pii> vii;
#define F first
#define S second
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define db(x) cout << #x << ": " << x << "\n";

void solve() {
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    if (a == 0) {
        cout << "1\n";
        return;
    }
    ll x = a, y = min(b, c);
    b -= y;
    c -= y;
    if (b > 0 && x - b <= -1) {
        cout << a + y * 2 + x + 1 << "\n";
        return;
    }
    if (c > 0 && x - c <= -1) {
        cout << a + y * 2 + x + 1 << "\n";
        return;
    }
    x -= b;
    x -= c;
    cout << a + y * 2 + b + c + min(x + 1, d) << "\n";
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--)
        solve();
}
