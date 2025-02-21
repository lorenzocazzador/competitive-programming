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
    vii v(3);
    for (auto &x : v)
        cin >> x.S >> x.F;
    sort(all(v));
    if (v[1].F == v[2].F)
        cout << abs(v[1].S - v[2].S) << "\n";
    else
        cout << "0\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--)
        solve();
}
