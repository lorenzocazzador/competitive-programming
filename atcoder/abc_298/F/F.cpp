#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    int n;
    cin >> n;
    map<ll, ll> row, col;
    map<pair<ll,ll>, ll> g;
    while (n--) {
        ll r, c, x;
        cin >> r >> c >> x;
        row[r] += x;
        col[c] += x;
        g[{r,c}] = x;
    }
    ll mxr = 0, mr;
    for (auto [a,b] : row) {
        if (b > mxr) {
            mr = a;
            mxr = b;
        }
    }
    ll mxc = 0, mc;
    for (auto [a,b] : col) {
        if (b > mxc) {
            mc = a;
            mxc = b;
        }
    }
    ll s = 0;
    for (auto [a,b] : col) {
        s = max(s, mxr + b - g[{mr, a}]);
    }
    for (auto [a,b] : row) {
        s = max(s, mxc + b - g[{a, mc}]);
    }
    cout << s << "\n";
}
