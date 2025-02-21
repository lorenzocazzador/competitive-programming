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
    sort(all(a), greater<int>());
    int i = 0;
    while(i + 1 < n && a[i] == a[i + 1]) i++;
    if (i + 1 == n) cout << "NO\n";
    else {
        cout << "YES\n";
        for (int j = 0; j < n; j++) {
            cout << a[(j + i) % n] << " ";
        }
        cout << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while(T--) solve();
}
