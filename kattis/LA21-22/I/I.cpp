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

map<string, int> m = { {"Mon", 0}, {"Tue", 1}, {"Wed", 2}, {"Thu", 3}, {"Fri", 4}, {"Sat", 5}, {"Sun", 6}};
int ans;

bool check(int x, bool xnot0) {
    if (x < 0 || (x == 0 && xnot0)) {
        ans = min(ans, -x);
        return true;
    } else return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string t; int n;
    cin >> t >> n;
    int d = m[t];
    ans = INT_MAX;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        bool xnot0 = (x != 0);
        int dw = (d - (x % 7) + 7) % 7;
        if (dw == 1) {
            x -= 30;
            dw = 3;
        }
        if (check(x, xnot0)) continue;
        if (dw == 3) {
            x -= 32;
            dw = 0;
        }
        if (check(x, xnot0)) continue;
        if (dw == 2) {
            x -= 30;
            dw = 4;
        }
        if (check(x, xnot0)) continue;
        if (dw == 4) {
            x -= 31;
            dw = 0;
        }
        if (check(x, xnot0)) continue;
        x %= 91;
        for (int i = 0; i < 2; i++) {
            x -= 30;
            if (check(x, xnot0)) continue;
        }
        x -= 31;
        if (check(x, xnot0)) continue;
    }
    cout << ans << "\n";
}
