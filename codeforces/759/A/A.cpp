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
    vector<int> f(n);
    for (int & x : f) cin >> x;
    int k = 1 + f[0];
    for (int i = 1; i < n; i++) {
        if (f[i] && f[i-1])
            k += 5;
        else if (f[i])
            k++;
        else if (!f[i-1]){
            cout << -1 << "\n";
            return;
        }
    }
    cout << k << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while(T--) solve();
}
