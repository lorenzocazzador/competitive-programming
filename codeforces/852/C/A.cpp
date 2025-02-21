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

void solve() {
    int n;
    cin >> n;
    vi a(n);
    for (int & x : a) cin >> x;
    int l = 0, r = n - 1, mn = 1, mx = n;
    while (l < r) {
        if (a[l] == mn) {
            l++;
            mn++;
        } else if (a[l] == mx) {
            l++;
            mx--;
        } else if (a[r] == mn) {
            r--;
            mn++;
        } else if (a[r] == mx) {
            r--;
            mx--;
        } else {
            cout << l + 1 << " " << r + 1 << "\n";
            return;
        }
    }
    cout << "-1\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while(T--) solve();
}
