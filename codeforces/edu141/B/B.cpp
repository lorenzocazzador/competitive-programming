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
    int a[n][n];
    int l = 1, r = n * n;
    bool t = 0;
    for (int i = 0; i < n; i++) {
        if (i % 2) {
            for (int j = n - 1; j >= 0; j--) {
                a[i][j] = (t ? r-- : l++);
                t ^= 1;
            }
        } else {
            for (int j = 0; j < n; j++) {
                a[i][j] = (t ? r-- : l++);
                t ^= 1;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while(T--) solve();
}
