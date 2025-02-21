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
    vector<pair<string, string>> v(n);
    map<string, int> m;
    for (auto & x : v) {
        cin >> x.F >> x.S;
        m[x.F]++;
        m[x.S]++;
    }
    bool ans = true;
    for (auto & x : v) {
        if (x.F == x.S) {
            ans &= (m[x.F] == 2);
        } else {
            ans &= (m[x.F] == 1 || m[x.S] == 1);
        }
    }
    cout << (ans ? "Yes\n" : "No\n");
}
