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

    int n;
    cin >> n;
    vi a(2 * n + 2);
    for (int & x : a) cin >> x;
    string s = "a";
    for (int i = 0; i < n - 1; i++) {
        int j = 2 * i + 3;
        if (a[j] == 1) {
            s += (s.back() == 'a' ? 'b' : 'a');
        } else {
            s += s.back();
        }
    }
    cout << s << "\n";
}
