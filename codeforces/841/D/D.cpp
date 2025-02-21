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

int n, m;
vector<vi> a;

bool found(int l) {
    for (int i = 0; i + l <= n; i++) {
        for (int j = 0; j + l <= m; j++) {
            bool valid = true;
            for (int x = 0; x < l && valid; x++) {
                for (int y = 0; y < l && valid; y++) {
                    if (a[i + x][j + y] < l) {
                        valid = false;
                    }
                }
            }
            if (valid) {
                return true;
            }
        }
    }
    return false;
}

bool found2(int l) {
    // cout << "entro " << l << endl;
    int i = 0, j = 0, x = 0, y = 0;

    while (i + l <= n) {
        while (j + l <= m) {
            // cout << i + x << " " << j + y << " " << a[i+x][j+y] << " i: " << i << endl;
            // cout << "entro i: " << i << " j: " << j << " x: " << x << " y: " << y << endl;
            if (a[i + x][j + y] >= l) {
                y++;
                if (y == l) {
                    x++;
                    y = 0;
                }
                if (x == l) {
                    // cout << "esco true\n";
                    return true;
                }
            } else {
                // cout << "entro qui\n";
                j = j + y + 1;
                if (j + l > m) {
                    j = 0; i++;
                }
                x = 0; y = 0;
                break;
            }
            // cout << "esco i: " << i << " j: " << j << " x: " << x << " y: " << y << endl;
            // cout << "esco qui i:" << i << " i+l:" << i+l << endl;
        }
    }
    // cout << "esco false\n";
    return false;
}

void solve() {
    cin >> n >> m;
    a.clear();
    a.resize(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    int l = 1, r = min(n, m), ans;
    while (l <= r) {
        int mid = (l + r) / 2;
        // cout << mid << " -> ";
        if (found2(mid)) {
            ans = mid;
            // cout << "found\n";
            l = mid + 1;
        } else {
            // cout << "not found\n";
            r = mid - 1;
        }
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while(T--) solve();
}
