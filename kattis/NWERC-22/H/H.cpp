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

vector<vi> adj;
int ans;

vi solve(int x, int p) {
    vector<vi> v;
    int max_d = 0, min_d = INT_MAX;
    for (int &k : adj[x]) {
        if (k != p) {
            v.push_back(solve(k, x));
            max_d = max(max_d, sz(v.back()));
            min_d = min(min_d, sz(v.back()));
        }
    }
    if(sz(v) < 2) min_d = 0;
    int new_d = min(max_d, min_d + 1) + 1;
    vi res(new_d, 0);
    res[0] = 1;
    for (vi &t : v) {
        for (int i = 0; i < sz(t); i++) {
            if (i + 1 < new_d)
                res[i + 1] += t[i];
            else
                ans += t[i];
        }
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    adj.resize(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    solve(1, -1);
    cout << ans << "\n";
}
