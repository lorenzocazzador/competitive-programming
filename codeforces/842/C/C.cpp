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
    vi a(n), occ(n + 1);
    bool no = false;
    for (int & x : a) {
        cin >> x;
        occ[x]++;
        if (occ[x] > 2) no = true;
    }
    if (no || occ[1] > 1) {
        cout << "NO\n";
        return;
    }
    vi b(n), c(n);
    set<int> bs, cs;
    for (int i = 1; i <= n; i++) {
        bs.insert(i);
        cs.insert(i);
    }
    for (int i = 0; i < n; i++) {
        if (bs.count(a[i])) {
            bs.erase(a[i]);
            b[i] = a[i];
        } else if (cs.count(a[i])) {
            cs.erase(a[i]);
            c[i] = a[i];
        } else assert(false);
    }
    for (int i = 0; i < n; i++) {
        if (b[i] == 0) {
            assert(c[i] != 0);
            auto it = bs.upper_bound(c[i]);
            if (it == bs.begin()) {
                cout << "NO\n";
                return;
            }
            it--;
            b[i] = *it;
            bs.erase(it);
        } else if (c[i] == 0) {
            assert(b[i] != 0);
            auto it = cs.upper_bound(b[i]);
            if (it == cs.begin()) {
                cout << "NO\n";
                return;
            }
            it--;
            c[i] = *it;
            cs.erase(it);
        } else assert(false);
    }
    cout << "YES\n";
    for (int & x : b) cout << x << " ";
    cout << "\n";
    for (int & x : c) cout << x << " ";
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while(T--) solve();
}
