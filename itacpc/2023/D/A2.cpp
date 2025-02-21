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
    vector<string> a;
    set<string> s;
    for (int i = 0; i < n; i++) {
        string x;
        cin >> x;
        s.insert(x);
        a.push_back(x);
    }
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        string t = "", x = "";
        int l = sz(a[i]);
        for (int j = 0; j < l; j++) {
            t = a[i][j] + t;
            if (s.find(t) != s.end()) {
                int len = l - j - 1;
                int cen = j + len / 2 + 1;
                if (len <= 1) {
                    ans++;
                } else if (len % 2 == 0) {
                    ans += (man_even[cen] * 2 >= len);
                } else {
                    ans += (man_odd[cen] * 2 - 1 >= len);
                }
            }

            x += a[i][l-j-1];
            if (s.find(x) != s.end()) {
                int len = l - j - 1;
                int cen = len / 2;
                if (len > 0 && len % 2 == 0) {
                    ans += (man_even[cen] * 2 >= len);
                } else {
                    ans += (man_odd[cen] * 2 - 1 >= len);
                }
            }
        }
    }
    cout << ans  << "\n";
}
