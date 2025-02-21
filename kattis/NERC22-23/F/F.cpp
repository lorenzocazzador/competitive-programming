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

    int n, a, b;
    cin >> n >> a >> b;
    if (n == 1) {
        cout << (a == b) << "\n";
        cout << a << ":" << b;
        return 0;
    }
    cout << max(0, n - a - b) << "\n";
    while (n > 2) {
        if (a-- > 0) cout << "1:0\n";
        else if (b-- > 0) cout << "0:1\n";
        else cout << "0:0\n";
        n--;
    }
    while (n) {
        if (a > 0 && n > 1 && b == 0) {
            cout << "1:0\n";
            a--;
        } else if (a > 0) {
            cout << a << ":0\n";
            a = 0;
        } else if (b > 0 && n > 1) {
            cout << "0:1\n";
            b--;
        } else if (b > 0) {
            cout << "0:" << b << "\n";
            b = 0;
        } else cout << "0:0\n";
        n--;
    }
}
