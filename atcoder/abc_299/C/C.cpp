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
    string s;
    cin >> n >> s;
    int ans = -1, tmp = 0;
    bool f = false;
    for (int i = 0; i < n; i++) {
        tmp += s[i] == 'o';
        if (s[i] == '-') {
            f = true;
            ans = max(ans, tmp);
            tmp = 0;
        }
    }
    if (f) ans = max(ans, tmp);
    cout << (ans == 0 ? -1 : ans) << "\n";
}
