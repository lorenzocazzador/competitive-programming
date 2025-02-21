#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
#define sz(x) (int)x.size()

vector<vector<int>> adj;
vector<bool> red;
constexpr ll MOD = 1000000007;

ll mul(ll a, ll b) {
    return (a % MOD * b % MOD) % MOD;
}

ll sum(ll a, ll b) {
    return (a % MOD + b % MOD) % MOD;
}

vi mul_pol(vi a, vi b) {
    vi res(sz(a) + sz(b) - 1, 0);
    for (int i = 0; i < sz(a); i++) {
        for (int j = 0; j < sz(b); j++) {
            res[i + j] = sum(res[i + j], mul(a[i], b[j]));
        }
    }
    return res;
}

void print(vi a) {
    cout << "[";
    for (int i = 0; i < sz(a); i++) {
        if (i > 0) cout << ", ";
        cout << a[i];
    }
    cout << "]\n";
}

vi dfs(int n) {
    vi pol;
    // cout << "n: " << n << "\n";
    for (int & x : adj[n]) {
        if (pol.empty()) pol = dfs(x);
        else pol = mul_pol(pol, dfs(x));
        // print(pol);
    }

    if (red[n]) {
        if (pol.empty()) pol = {0, 1};
        else if (sz(pol) == 1) pol.push_back(1);
        else pol[1] = (pol[1] + 1) % MOD ;
    } else {
        if (pol.empty()) pol = {1};
        else pol[0] = (pol[0] + 1) % MOD;
    }

    if (adj[n].empty()) {
        if (pol.empty()) pol = {1};
        else pol[0] = (pol[0] + 1) % MOD;
    }

    // cout << n << " -> "; print(pol);
    return pol;
}

int main() {
    int n, m;
    cin >> n >> m;
    adj.resize(n);
    red.resize(n, false);
    for (int i = 1; i < n; i++) {
        int x;
        cin >> x;
        x--;
        adj[x].push_back(i);
    }
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        x--;
        red[x] = true;
    }
    vi res = dfs(0);
    for (int i = 0; i <= m; i++) {
        cout << (i < sz(res) ? res[i] : 0) << "\n";
    }
}
