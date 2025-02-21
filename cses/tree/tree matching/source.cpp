#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef long long ll;

vector<vi> adj;
int dp[200010][2];

void solve(int x, int p = -1) {
    dp[x][0] = dp[x][1] = 0;
    for (int &y : adj[x]) {
        if (y != p) {
            solve(y, x);
        }
        dp[x][0] += dp[y][1];
    }
    for (int &y : adj[x]) {
        if (y != p) {
            dp[x][1] = max(dp[x][1], dp[x][0] - dp[y][1] + dp[y][0] + 1);
        }
    }
    dp[x][1] = max(dp[x][1], dp[x][0]);
}

int main() {
    int n;
    cin >> n;
    adj.resize(n);
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    solve(0);
    cout << max(dp[0][0], dp[0][1]) << "\n";
}
