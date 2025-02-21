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

int res;

int digit(int x) {
    res++;
    return to_string(x).size();
}

void print_vec(vi & m) {
    cout << "vec: ";
    for (int & x : m)
        cout << x << " ";
    cout << "\n";
}

void solve() {
    int n, x;
    res = 0;
    cin >> n;
    map<int,int> m, a, b;
    for (int i = 0; i < n; i++) {
        cin >> x;
        m[x]++;
    }
    for (int i = 0; i < n; i++) {
        cin >> x;
        if (m[x] > 0) {
            m[x]--;
        } else if(x > 9) {
            b[digit(x)]++;
        } else {
            b[x]++;
        }
    }

    for (auto & x : m) {
        if (x.S > 0) {
            int t = x.S;
            while (t--) {
                if (x.F > 9)
                    a[digit(x.F)]++;
                else
                    a[x.F]++;
            }
        }
    }

    for (int i = 2; i <= 9; i++) {
        while(a[i] > 0 && b[i] > 0) {
            a[i]--;
            b[i]--;
        }
        res += a[i] + b[i];
    }

    cout << res << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while(T--) solve();
}
