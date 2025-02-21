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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int q;
    cin >> q;
    map<int, pii> r;
    int n = 0;
    vi v;
    while (q--) {
        int t; cin >> t;
        if (t == 1) {
            int x;
            cin >> x;
            v.push_back(x);
            n++;
        } else {
            int x, y;
            cin >> x >> y;
            r[x] = {y, n};
        }
    }

    for (int i = 0; i < n; i++) {
        int y = v[i];
        while (true) {
            auto it = r.find(y);
            if (it != r.end()) {
                pii p = it->S;
                if (p.S < i)
                    y = p.F;
                else break;
            } else break;
        }
    }
}
