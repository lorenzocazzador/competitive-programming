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

int check(vi & p, int fp) {
    if (fp == 0) return 1;
    if (fp == 2) {
        int c = 0;
        for (int i = 0; i < sz(p) - 1; i++)
            c += (p[i] == p[i + 1] + 1);
        if (c == 1) return 0;
    }
    return -1;
}

void solve() {
    int n;
    cin >> n;
    vi p(n), pos(n + 1);
    int fp = 0;
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        pos[p[i]] = i;
        if (p[i] != i + 1) fp++;
    }
    int t = check(p, fp);
    if (t != -1) {
        cout << t << "\n";
        return;
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (p[i] != i + 1 && p[i] != i + 2 && p[i] != i) {
            int ind = pos[i + 1];
            swap(p[i], p[ind]);
            assert(p[i] == i + 1);
            pos[p[ind]] = ind;
            fp--;
            fp -= (p[ind] == ind + 1);
            ans++;
        }
        int t = check(p, fp);
        if (t != -1) {
            cout << ans + t << "\n";
            return;
        }
    }
    assert(false);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while(T--) solve();
}
