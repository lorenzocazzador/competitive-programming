#include <bits/stdc++.h>
using namespace std;

int solve() {
    int n, k;
    cin >> n >> k;
    vector<int> c(n);
    for (int & x : c) cin >> x;
    sort(c.begin(), c.end());
    vector<pair<int,int>> diff(n - 1);
    for (int i = 0; i + 1 < n; i++) {
        diff[i] = {c[i+1] - c[i], i};
    }
    sort(diff.begin(), diff.end(), greater<pair<int,int>>());
    vector<int> cut(k);
    for (int i = 0; i < k - 1; i++) {
        cut[i] = diff[i].second;
    }
    cut[k - 1] = n - 1;
    sort(cut.begin(), cut.end());
    int mn = c[0], ans = 0;
    for (int i = 0; i < k; i++) {
        int t = cut[i];
        ans += c[t] - mn;
        if (t + 1 < n)
            mn = c[t + 1];
    }
    return ans;
}

int main() {
    int t;
    cin >> t;
    for (int nt = 1; nt <= t; nt++) {
        cout << "Case #" << nt << ": " << solve() << "\n";
    }
}
