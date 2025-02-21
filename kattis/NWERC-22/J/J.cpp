#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
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
    vector<array<int, 3>> v(n);
    for (int i = 0; i < n; i++) {
        int a, t;
        cin >> a >> t;
        v[i] = {a, a + t, i};
    }
    sort(all(v), [](auto &a, auto &b){ return a[0] == b[0] ? (a[1] > b[1]) : (a[0] < b[0]);});
    vi ans(n, -1);
    map<int, int> s;
    s[INT_MAX] = 0;
    for (auto & [e, u, i] : v) {
        ans[i] = s.lower_bound(u)->S + 1;
        s[u] = ans[i];
        auto it = s.find(u);
        if (it != s.begin() && prev(it)->S <= ans[i]) s.erase(prev(it));
    }
    for (int i = 0; i < n; i++) {
        cout << ans[i] - 1 << " ";
    }
}
