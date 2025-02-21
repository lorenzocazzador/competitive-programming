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
    if (n == 3) {
        cout << "3 2 1\n1 3 2\n3 1 2\n";
    } else {
        vi v(n);
        for (int i = 0; i < n; i++) v[i] = n-i;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << v[(i+j)%n] << " ";
            }
            cout << "\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while(T--) solve();
}
