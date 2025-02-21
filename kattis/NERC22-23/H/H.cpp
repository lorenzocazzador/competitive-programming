#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define get(s, x, y)                                                           \
    s = test(x, y);                                                            \
    if (found(s))                                                              \
        return 0;

bool found(string s) {
    if (s.back() == '!')
        return true;
    return false;
}
string test(ll x, ll y) {
    string ans;
    cout << x << " " << y << endl;
    getline(cin, ans);
    return ans;
}
signed main() {
    const ll mam = 10;

    string ans, ans1, closer, further, same;

    get(ans, 0, 0);
    get(same, 0, 0);
    get(closer, 1, 1);
    if (closer == same) {
        // Solution is in either (1, 0) or (0, 1)
        get(ans, 1, 0);
        get(ans, 0, 1);
    }
    ll lx = 0, ly = 0, rx = mam, ry = mam;
    while (lx + 1 < rx) { // Keep searching until we get a 2x2
        ll mx = (lx + rx) / 2;
        ll my = (ly + ry) / 2;
        get(ans, mx + 1, my);
        get(ans, mx, my);
        if (ans == closer) {
            // Then it is in range [lx, mx]
            rx = mx;
        } else {
            // Then it is in range [mx + 1, rx]
            lx = mx + 1;
        }
        get(ans, mx, my + 1);
        if (ans == closer) {
            // Then it is in range [my + 1, ry]
            ly = my + 1;
        }
        else {
            // Then it is in range [ly, my]
            ry = my;
        }
    }
    get(ans, lx, ly);
    get(ans, lx + 1, ly);
    if (ans == closer) {
        get(ans, lx + 1, ly + 1);
    } else {
        get(ans, lx, ly + 1);
    }

    return 0;
}
