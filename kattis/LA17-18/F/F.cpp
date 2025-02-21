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

const int MAXN = 100010;
ogni flusso massimo ti dà una configurazione accettabile
una configurazione accettabile corrisponde ad un flusso massimo

struct Node {
    int b, f;
    ll d;
    bool operator< (const Node& x) const {
        return b < x.b || (b == x.b && f > x.f);
    }
};

ll fen[MAXN];

void update(int i, ll x) {
    for (; i < MAXN; i += (i & (-i))) {
        fen[i] = max(fen[i], x);
    }
}

ll query(int i) {
    ll ans = 0;
    for (; i > 0; i -= (i & (-i))) {
        ans = max(ans, fen[i]);
    }
    return ans;
}

int n;
vector<Node> a;
vi vec;

int main() {
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].b >> a[i].f >> a[i].d;
        vec.push_back(a[i].f);
    }
    sort(all(vec));
    vec.erase(unique(all(vec)), vec.end());
    sort(all(a));

    int m = -1;
    for (int i = 1, j = 0; i < n; i++) {
        if (a[i].b == a[j].b && a[i].f == a[j].f) a[j].d += a[i].d;
        else a[++j] = a[i];
        m = j;
    }
    n = m + 1;

    for (int i = 0; i < n; i++) {
        int pos = lower_bound(vec.begin(), vec.end(), a[i].f) - vec.begin();
        pos++;
        update(pos, query(pos - 1) + a[i].d);
    }
    cout << query(sz(vec)) << "\n";
}
