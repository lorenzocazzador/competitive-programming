#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef long long ll;

int main() {
    int n;
    cin >> n;
    vi a(n);
    for (int & x : a) cin >> x;
    vector<ll> prefix_sum(n + 1);
    for (int i = 0; i < n; i++) {
        prefix_sum[i + 1] = a[i] + prefix_sum[i];
    }
    ll ans = LLONG_MIN, mn = prefix_sum[0];
    for (int i = 1; i <= n; i++) {
        ans = max(ans, prefix_sum[i] - mn);
        mn = min(mn, prefix_sum[i]);
    }
    cout << ans << "\n";
}
