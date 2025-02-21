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

int m[110][110], rr, cc;
vector<pii> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

bool inside(int i, int j) {
    return i >= 0 && j >= 0 && i < rr && j < cc;
}

int solve(int r, int c) {
    priority_queue<pair<int, pii>> pq;
    vector<bool> vis(rr * cc + 1, false);
    vis[m[r][c]] = true;
    pq.push({-m[r][c], {r,c}});
    int mx = 0, res = 0;
    while (!pq.empty()) {
        int v = -pq.top().F; pii act = pq.top().S; pq.pop();
        mx = max(mx, v);
        res++;
        for (pii & p : dir) {
            int nr = act.F + p.F, nc = act.S + p.S;
            if (inside(nr, nc) && m[nr][nc] > mx && !vis[m[nr][nc]]) {
                pq.push({-m[nr][nc], {nr, nc}});
                vis[m[nr][nc]] = true;
            }
        }
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> rr >> cc;
    for (int i = 0; i < rr; i++) {
        for (int j = 0; j < cc; j++) {
            cin >> m[i][j];
        }
    }
    int ans = 0;
    for (int i = 0; i < rr; i++) {
        for (int j = 0; j < cc; j++) {
            ans = max(ans, solve(i, j));
        }
    }
    cout << ans << "\n";
}
