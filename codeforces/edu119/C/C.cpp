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
    ll n, k, x;
    cin >> n >> k >> x;
    string s;
    cin >> s;
    vll b;
    string t = "";
    ll c = 1;
    for (int i = 1; i < n; i++) {
        if (s[i] == s[i-1]) c++;
        else {
            t += s[i-1];
            b.push_back(c);
            c = 1;
        }
    }
    t += s[n-1];
    b.push_back(c);

    // cout << t << "\n";
    // for (ll & x : b) cout << x << " ";
    // cout << "\n";

    vll r(sz(t), 0);
    x--;
    for (int i = sz(t)-1; i >= 0; i--) {
        if (t[i] == '*') {
            r[i] = x % (b[i] * k + 1);
            x /= (b[i] * k + 1);
        }
    }

    for (int i = 0; i < sz(t); i++) {
        if (t[i] == '*')
            cout << string(r[i], 'b');
        else
            cout << string(b[i], 'a');
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while(T--) solve();
}
