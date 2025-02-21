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
    ll n, m;
    cin >> n >> m;
    cout << "? 1 1" << endl;
    ll a1;
    cin >> a1; a1++;
    cout << "? " << min(a1, n) << " " << min(a1, m) << endl;
    ll a2;
    cin >> a2;
    if (a1 > n) {
        cout << "! " << n - a2 << " " << a1 << endl;
        return;
    }
    if (a1 > m) {
        cout << "! " << a1 << " " << m - a2 << endl;
        return;
    }
    assert(a1 - a2 > 0);
    cout << "? " << a1 << " " << a1 - a2 << endl;
    ll a3;
    cin >> a3;
    if (a3 == 0) {
        cout << "! " << a1 << " " << a1 - a2 << endl;
    } else {
        cout << "! " << a1 - a2 << " " << a1 << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);

    int T;
    cin >> T;
    while(T--) solve();
}
