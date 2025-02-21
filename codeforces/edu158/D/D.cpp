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

void print(multiset<int> s) {
    for (int x : s) cout << x << " ";
    cout << "\n\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vi a(n);
    for (int & x : a) cin >> x;
    multiset<int> s;
    for (int i = 0; i < n; i++) s.insert(a[i] + i);
    int ans = *s.rbegin();
    // print(s);
    for (int i = 0; i < n - 1; i++) {
        auto it1 = s.find(a[i]);
        assert(it1 != s.end());
        s.erase(it1);
        auto it2 = s.find(a[i + 1] + i + 1);
        assert(it2 != s.end());
        s.erase(it2);
        s.insert(a[i] + n - i - 1);
        s.insert(a[i+1]);
        // print(s);
        ans = min(ans, *s.rbegin());
    }
    cout << ans << "\n";
}
