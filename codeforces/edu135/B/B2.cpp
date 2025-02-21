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

void solve() {
    int n;
    cin >> n;
    vi perm(n);
    iota(perm.begin(), perm.end(), 1);
    for (int i = n % 2; i <= n - 4; i += 2) {
        swap(perm[i], perm[i + 1]);
    }
    for (int i = 0; i < n; i++)
        cout << perm[i] << " ";
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--)
        solve();
}
