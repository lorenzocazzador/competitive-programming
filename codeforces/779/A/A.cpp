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
    string s;
    cin >> s;
    int ans = 0;
    for (int i = 0; i < n - 1; i++) {
        if (s[i] == '0' && s[i+1] == '0')
            ans += 2;
        if (s[i] == '0' && s[i+1] == '1' && i+2 < n && s[i+2] == '0')
            ans++;
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
