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
    int n;
    cin >> n;
    int b = 0, w = 0;
    vii v(n);
    for (int i = 0; i < n; i++) {
        int x; char c;
        cin >> x >> c;
        v[i] = {x, c == 'B'};
        if (c == 'B') b += v[i].F;
        else w += v[i].F;
    }
    if (b == 0 || w == 0) {
        cout << b + w << "\n";
        return;
    }
    int gcd = __gcd(b, w);
    b /= gcd;
    w /= gcd;
    // cout << "ratio " << w << " : " << b << "\n";
    int tb = 0, tw = 0, ans = 0;
    if (v[0].S) tb += v[0].F;
    else tw += v[0].F;
    for (int i = 1; i < n; i++) {
        if (v[i].S) {
            // black
            int bn = (tw / w) * b - tb;
            if (bn > 0 && tw % w == 0 && bn <= v[i].F) {
                ans++;
                tw = 0;
                tb = v[i].F - bn;
            } else {
                tb += v[i].F;
            }
        } else {
            // white
            int wn = (tb / b) * w - tw;
            if (wn > 0 && tb % b == 0 && wn <= v[i].F) {
                ans++;
                tb = 0;
                tw = v[i].F - wn;
            } else {
                tw += v[i].F;
            }
        }
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
