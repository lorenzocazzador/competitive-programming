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
    vi v(n), pos(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        pos[v[i]] = i;
    }
    int a = n / 2, b = n / 2 + 1 + (n % 2), pa = pos[a + (n % 2)], pb = pos[b - (n % 2)];
    while (a > 0 && b <= n) {
        if (pos[b] < pos[a] || pos[b] < pb || pos[a] > pa) {
            cout << a << "\n";
            return;
        }
        pa = min(pos[a], pa);
        pb = max(pos[b], pb);
        a--; b++;
    }

    cout << "0\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while(T--) solve();
}
