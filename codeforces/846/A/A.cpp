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
    vi p, d;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x % 2) d.push_back(i + 1);
        else p.push_back(i + 1);
    }
    if (sz(d) > 2) cout << "YES\n" << d[0] << " " << d[1] << " " << d[2] << "\n";
    else if (sz(p) > 1 && sz(d) > 0) cout << "YES\n" << d[0] << " " << p[0] << " " << p[1] << "\n";
    else cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while(T--) solve();
}
