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

bool f(int a, int b, int c) {
    return (b % 2) == (c % 2);
}

void solve() {
    int a, b, c;
    cin >> a >> b >> c;
    cout << f(a, b, c) << " " << f(b, c, a) << " " << f(c, a, b) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while(T--) solve();
}
