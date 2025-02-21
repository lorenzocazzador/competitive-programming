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
    string s;
    cin >> s;
    bool r = false, g = false, b = false, ans = true;
    for (char c : s) {
        if (c == 'r')
            r = true;
        else if (c == 'g')
            g = true;
        else if (c == 'b')
            b = true;
        else if (c == 'R')
            ans &= r;
        else if (c == 'G')
            ans &= g;
        else if (c == 'B')
            ans &= b;
    }
    cout << (ans ? "YES\n" : "NO\n");
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while(T--) solve();
}
