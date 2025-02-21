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

vii q;
vi ans, prefix;
int prec;

void insert(int p, int c) {
    q.push_back({p,c});
    prefix.push_back(c);
}

void print(vi a) {
    bool first = true;
    cout << "{ ";
    for (int & x : a) {
        cout << (first ? "" : ", ") << x;
        first = false;
    }
    cout << " }\n";
}

void solve2(vi & a) {
    int i = 1;
    while (i < sz(a) && a[0] != a[i]) {
        i++;
    }
    int z = i, j = 0;
    while (j < z && i < sz(a) && a[j] == a[i]) {
        j++;
        i++;
    }
    int t = i;
    while (j < z) {
        insert(prec + i, a[j]);
        j++;
        i++;
    }

    ans.push_back(z * 2);
    prec += z * 2;

    vi a_next;
    reverse(all(prefix));
    for (int k = 0; k < sz(prefix); k++)
        a_next.push_back(prefix[k]);
    prefix.clear();
    for (int k = t; k < sz(a); k++)
        a_next.push_back(a[k]);

    if (sz(a_next) > 0)
        solve2(a_next);
}


void solve() {
    q.clear(); ans.clear(); prefix.clear(); prec = 0;
    int n;
    cin >> n;
    vi a(n);
    map<int, int> occ;
    for(int & x : a) {
        cin >> x;
        occ[x]++;
    }

    if (n % 2) {
        cout << "-1\n";
        return;
    }
    for (auto & x : occ) {
        if (x.S % 2) {
            cout << "-1\n";
            return;
        }
    }

    solve2(a);

    cout << sz(q) << "\n";
    for (pii & x : q)
        cout << x.F << " " << x.S << "\n";
    cout << sz(ans) << "\n";
    for (int & x : ans)
        cout << x << " ";
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while(T--) solve();
}
