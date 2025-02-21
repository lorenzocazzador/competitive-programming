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

string s;
vii adj;

int dfs(int x) {
    int ans = INT_MAX;
    if (adj[x].F >= 0)
        ans = min(ans, dfs(adj[x].F) + (s[x] != 'L'));
    if (adj[x].S >= 0)
        ans = min(ans, dfs(adj[x].S) + (s[x] != 'R'));
    return (ans == INT_MAX ? 0 : ans);
}

void solve() {
    int n;
    cin >> n >> s;
    adj.clear();
    adj.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> adj[i].F >> adj[i].S;
        adj[i].F--;
        adj[i].S--;
    }
    cout << dfs(0) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while(T--) solve();
}
