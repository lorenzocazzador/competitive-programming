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
    int n;
    cin >> n;
    vector<vi> m(n + 1, vector<int>());
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        m[x].push_back(i + 1);
    }
    int q;
    cin >> q;
    while (q--) {
        int l, r, x;
        cin >> l >> r >> x;
        auto it1 = lower_bound(all(m[x]), l);
        auto it2 = upper_bound(all(m[x]), r);
        int ans = it2 - it1;
        cout << ans << "\n";
    }
}
