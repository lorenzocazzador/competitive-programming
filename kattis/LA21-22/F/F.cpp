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

vector<vi> adj;
vector<char> ans;
int n;

void dfs(int x) {
    if (ans[x] != '0')
        return;
    ans[x] = 'B';
    for (int & y : adj[x]) {
        if (y != n) {
            dfs(y);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int m;
    cin >> n >> m;
    adj.resize(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    ans.resize(n + 1, '0');
    dfs(n - 1);
    for (int i = 1; i <= n; i++) cout << (ans[i] == '0' ? 'A' : 'B');
    cout << "\n";
}
