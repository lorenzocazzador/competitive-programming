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

vii v = {{4,2}, {1,1}, {1,2}, {1,3}, {2,1}, {2,2}, {2,3}, {3,1}, {3,2}, {3,3}};

bool can(int x) {
    string s = to_string(x);
    pii act = v[s[0] - '0'];
    for (int i = 1; i < sz(s); i++) {
        pii tmp = v[s[i] - '0'];
        if (!(act.F <= tmp.F && act.S <= tmp.S)) return false;
        act = tmp;
    }
    return true;
}

void solve() {
    int k;
    cin >> k;
    if (can(k)) cout << k << "\n";
    else {
        int a = k - 1;
        while (!can(a) && a > 0) a--;
        int b = k + 1;
        while (!can(b) && b < 200) b++;
        if (k - a < b - k)
            cout << a << "\n";
        else
            cout << b << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while(T--) solve();
}
