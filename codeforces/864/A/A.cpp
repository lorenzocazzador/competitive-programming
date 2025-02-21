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

int n, m;

bool inside(int x, int y) {
    return x > 0 && y > 0 && x <= n && y <= m;
}

vii dir = {{-1,0},{0,-1},{1,0},{0,1}};

void solve() {
    cin >> n >> m;
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    int a = 0, b = 0;
    for (auto & x : dir) {
        a += inside(x1 + x.F, y1 + x.S);
        b += inside(x2 + x.F, y2 + x.S);
    }
    cout << min(a, b) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while(T--) solve();
}
