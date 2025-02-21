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
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;
    vi adj[n];
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    for (int i = 0; i < n; i++) {
        vi t(n);
        queue<int> q;
        for (int & v : adj[i])
            q.push(v);
        while (q.size()) {
            int x = q.front(); q.pop();
            for (int & v : adj[x]) {
                if (v == i) continue;
                t[v]++;
                if (t[v] >= k) {
                    cout << "YES\n";
                    return 0;
                }
            }
        }
    }
    cout << "NO\n";
}
