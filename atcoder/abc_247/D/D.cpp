#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<pii> vii;
#define F first
#define S second
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define db(x) cout << #x << ": " << x << "\n";

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    queue<pll> q;
    while (n--) {
        int t;
        cin >> t;
        if (t == 1) {
            ll x, c;
            cin >> x >> c;
            q.push({x, c});
        } else {
            ll c;
            cin >> c;
            ll res = 0;
            while (c > 0) {
                pll & a = q.front();
                if (a.S > c) {
                    a.S -= c;
                    res += a.F * c;
                    c = 0;
                } else {
                    c -= a.S;
                    res += a.F * a.S;
                    q.pop();
                }
            }
            cout << res << "\n";
        }
    }
}
