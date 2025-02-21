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
    int n, k;
    cin >> n >> k;
    int v[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> v[i][j];
        }
    }
    int mim = 0;
    for (int i = 0, x = n - 1; i < n / 2; i++, x--) {
        for (int j = 0, y = n - 1; j < n; j++, y--) {
            mim += (v[i][j] != v[x][y]);
        }
    }
    if (n % 2) {
        int i = n / 2;
        for (int j = 0, y = n - 1; j < n / 2; j++, y--) {
            mim += (v[i][j] != v[i][y]);
        }
    }

    if (mim > k) {
        cout << "NO\n";
    } else if (n % 2 == 0 && (k - mim) % 2) {
        cout << "NO\n";
    } else cout << "YES\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while(T--) solve();
}
