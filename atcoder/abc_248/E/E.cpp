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

    int n, k;
    cin >> n >> k;
    vector<pair<ll,ll>> v(n);
    for (auto & x : v) cin >> x.F >> x.S;

    if (k == 1) {
        cout << "Infinity\n";
        return 0;
    }

    set<set<int>> lines;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            set<int> s = {i, j};
            long double slope;
            bool vertical = false;
            if (v[i].F == v[j].F)
                vertical = true;
            else
                slope = (long double)(v[i].S - v[j].S) / (long double)(v[i].F - v[j].F);

            for (int z = 0; z < n; z++) {
                if (z != i && z != j) {
                    if (vertical && v[z].F == v[i].F) {
                        s.insert(z);
                    } else if (!vertical && v[z].F != v[i].F) {
                        long double slope2 = (long double)(v[i].S - v[z].S) / (long double)(v[i].F - v[z].F);
                        if (abs(slope - slope2) < 1e-18) {
                            s.insert(z);
                        }
                    }
                }
            }
            if (sz(s) >= k) {
                lines.insert(s);
            }
        }
    }
    // for (auto & x : lines) {
    //     for (auto & y : x)
    //         cout << y << " ";
    //     cout << endl;
    // }
    cout << sz(lines) << "\n";
}
