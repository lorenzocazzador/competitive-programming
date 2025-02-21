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

    int n;
    cin >> n;
    vii a(n);
    for (pii & x: a) cin >> x.S >> x.F;
    sort(all(a));
    int p = 0, mx = 0;
    for (int i = 0; i < n; i++) {
        p += a[i].S;
        while (i + 1 < n && a[i + 1].F == a[i].F) {
            i++;
            p += a[i].S;
        }
        mx = max(mx, p);
    }
    cout << mx << "\n";
}
