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

    string b;
    int s;
    cin >> b >> s;
    b += b;
    int n = sz(b);
    vi next(n, -1);
    next[n - 1] = n;
    for (int i = n - 2; i >= 0; i--) {
        if (b[i] == 'E') next[i] = i;
        else next[i] = next[i + 1];
    }
    ll ans = 0;
    for (int i = 0; i < n / 2; i++) {
        ans += max(0, i + s - next[i]);
    }
    cout << ans << "\n";
}
