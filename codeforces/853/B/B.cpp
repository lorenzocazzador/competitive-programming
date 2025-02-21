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
    int l = -1;
    for (int i = 0; i < n / 2; i++) {
        if (s[i] != s[n - 1 - i]) {
            if (l != - 1 && i - l > 1) {
                cout << "No\n";
                return;
            }
            l = i;
        }

    }
    cout << "Yes\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while(T--) solve();
}
