#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<int> ans;

int dfs(int x) {
    for (int & y : adj[x]) {
        ans[x] += dfs(y);
    }
    return ans[x] + 1;
}

int main() {
    int n;
    cin >> n;
    adj.resize(n);
    for (int i = 1; i < n; i++) {
        int x;
        cin >> x;
        adj[--x].push_back(i);
    }
    ans.resize(n);
    dfs(0);
    for (int & x : ans) cout << x << " ";
}
