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
    if (n % 2 == 0) {
        cout << "No\n";
        return;
    }
    cout << "Yes\n";
    int i = 1, j = n + n / 2 + 1;
    while (j <= 2 * n) {
        cout << i++ << " " << j++ << "\n";
    }
    j = n + 1;
    while (i <= n) {
        cout << i++ << " " << j++ << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while(T--) solve();
}
