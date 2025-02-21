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
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j && __gcd(a[i], a[j]) <= 2) {
                cout << "Yes\n";
                return;
            }
        }
    }
    cout << "No\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while(T--) solve();
}
