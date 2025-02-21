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

    int h, w;
    cin >> h >> w;
    vii v(h);
    for (int i = 0; i < h; i++) {
        int mn = INT_MAX, mx = 1;
        for (int j = 0; j < h; j++) {
            int x; cin >> x;
            if (x) {
                mn = min(mn, x);
                mx = max(mx, x);
            }
        }
        v[i] = {mn, mx};
    }
    sort(all(v));
    bool ans = true;
    for (int i = 0; i < h - 1; i++) {
        ans &= (v[i].S <= v[i+1].F);
    }
    cout << (ans ? "Yes" : "No");
}
