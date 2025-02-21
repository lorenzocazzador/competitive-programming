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

vi getV (vi & a) {
    vi res(sz(a));
    for (int i = 0; i < sz(a); i++) {
        res[i] = a[i];
        int sum = a[i];
        for (int j = i + 1; j < sz(a); j++) {
            sum += a[j];
            res[i] = max(res[i], sum);
        }
    }
    return res;
}

void solve() {
    int n, m;
    cin >> n;
    vi r(n);
    for (int & x : r) cin >> x;
    cin >> m;
    vi b(m);
    for (int & x : b) cin >> x;
    vi c(n+m);
    vi r1 = getV(r), b1 = getV(b);

    int i = 0, j = 0, k = 0;
    while (i < n && j < m) {
        if (r1[i] > b1[j])
            c[k++] = r[i++];
        else
            c[k++] = b[j++];
    }
    while (i < n)
        c[k++] = r[i++];
    while (j < m)
        c[k++] = b[j++];
    int res = 0, sum = 0;
    for (int & x : c) {
        sum += x;
        res = max(res, sum);
    }
    cout << res << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while(T--) solve();
}
