#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef vector<pii> vii;
#define F first
#define S second
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define db(x) cout << #x << ": " << x << "\n";

vi perm;
int n;

int solve2() {
    int x = 0;
    for (int i = 0; i < n; i++) {
        if (x < perm[i])
            x += perm[i];
        else
            x = 0;
    }
    return x;
}

void solve() {
    perm.clear();
    perm.resize(n);
    iota(perm.begin(), perm.end(), 1);
    for (int i = n % 2; i <= n - 4; i += 2) {
        swap(perm[i], perm[i + 1]);
    }
    for (int i = 0; i < n; i++)
        cout << perm[i] << " ";
    cout << "\n";
    // cout << n - 2 << " " << n - 3 << " " << n - 1 << " " << n << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    for (int i = 4; i <= 100; i++) {
        n = i;
        solve();
        int res = solve2();
        if (res == 0) {
            cout << "zero: " << i << "\n";
        }
        // cout << solve2() << " " << 2 * i - 1 << "\n";
    }
}
