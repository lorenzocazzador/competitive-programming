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

    int n, m;
    cin >> n >> m;
    vi a(n);
    ll tot = 0;
    for (int & x : a) {
        cin >> x;
        tot += x;
    }
    sort(all(a));
    ll sum = 0, tsum = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] == a[i-1] || a[i] == a[i-1] + 1) {
            tsum += a[i];
        } else {
            tsum = a[i];
        }
        sum = max(tsum, sum);
    }
    for (int i = 0; i < n; i++) {
        int p = i - 1 >= 0 ? i - 1 : n - 1;
        if (a[i] == a[p] || a[i] == (a[p] + 1) % m) {
            tsum += a[i];
        } else {
            tsum = a[i];
        }
        sum = max(tsum, sum);
    }
    cout << max(tot - sum, 0LL) << "\n";
}
