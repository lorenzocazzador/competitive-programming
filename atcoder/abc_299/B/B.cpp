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

    int n, t;
    cin >> n >> t;
    vi c(n), r(n);
    for (int & x : c) cin >> x;
    for (int & x : r) cin >> x;
    int id = -1, mx = 0;
    for (int i = 0; i < n; i++) {
        if (c[i] == t && r[i] > mx) {
            mx = r[i];
            id = i + 1;
        }
    }
    if (id == -1) {
        t = c[0];
        for (int i = 0; i < n; i++) {
            if (c[i] == t && r[i] > mx) {
                mx = r[i];
                id = i + 1;
            }
        }
    }
    cout << id << "\n";
}
