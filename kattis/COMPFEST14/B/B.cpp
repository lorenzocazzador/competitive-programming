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

    int n, d;
    cin >> n >> d;
    vi a(n);
    for (int & x : a) cin >> x;
    sort(all(a), greater<int>());
    int res = 0;
    for (int i = 0; i < sz(a) && n > 0; i++) {
        int tmp = d / a[i] + 1;
        if (tmp <= n) {
            n -= tmp;
            res++;
        }
    }
    cout << res << "\n";
}
