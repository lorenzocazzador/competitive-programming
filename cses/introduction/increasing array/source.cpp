#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef long long ll;

int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (ll & x : a) cin >> x;
    ll res = 0;
    for (int i = 1; i < n; i++) {
        res += max(0LL, a[i-1] - a[i]);
        a[i] += max(0LL, a[i-1] - a[i]);
    }
    cout << res << "\n";
}
