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

int n;
vector<string> s;
vector<bool> used;

bool canWinFirst(int x, bool f) {
    // cout << "0: " << s[x] << endl;
    bool ans = f;
    for (int i = 0; i < n; i++) {
        if (!used[i] && s[x].back() == s[i].front()) {
            used[i] = true;
            bool tmp = canWinFirst(i, !f);
            used[i] = false;
            if (tmp == f) {
                return f;
            }
            ans = !f;
        }
    }
    // cout << "2: " << s[x] << " -> " << ans << endl;
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    s.resize(n);
    for (auto & x : s) cin >> x;
    for (int i = 0; i < n; i++) {
        used.clear();
        used.resize(n, false);
        used[i] = true;
        if (canWinFirst(i, true)) {
            cout << "First\n";
            return 0;
        }
    }
    cout << "Second\n";
}
