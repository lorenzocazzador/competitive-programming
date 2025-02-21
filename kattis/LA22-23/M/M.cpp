#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef vector<pii> vii;
#define F first
#define S second
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define db(x) cout << #x << ": " << x << "\n";

const int MAXC = 105;
int r, c;
bitset<MAXC> n;
vector<bitset<MAXC>> v;
vector<bitset<MAXC>> s;

void shift(bitset<MAXC> &b) {
    b <<= 1;
    b[0] = b[c];
    b[c] = 0;
}

void print(int sh) {
    string str = "";
    for (int i = 0; i < c; i++) {
        str = (s[sh][i] ? "1" : "0") + str;
    }
    cout << str << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> r >> c;
    cin >> n;
    v.resize(r);
    for (int i = 0; i < r; i++) {
        cin >> v[i];
    }
    s.resize(c * 2);
    vector<vector<bool>> vis(r, vector<bool>(c * 2, false));
    priority_queue<pii> pq;
    for (int i = 0; i < c; i++) {
        s[i] = n;
        shift(n);
        if ((s[i] & v[0]).none()) {
            pq.push({0, i});
            vis[0][i] = true;
        }
    }
    for (int i = 0; i < c / 2; i++) {
        bool a = n[i], b = n[c - i - 1];
        n[c - i - 1] = a;
        n[i] = b;
    }
    for (int i = 0; i < c; i++) {
        s[i + c] = n;
        shift(n);
        if ((s[i + c] & v[0]).none()) {
            pq.push({0, i + c});
            vis[0][i + c] = true;
        }
    }
    while (!pq.empty()) {
        int l = pq.top().F, sh = pq.top().S;
        // cout << "ENTRO: " << l << " " << sh << " "; print(sh);
        pq.pop();
        if (l == r - 1) {
            cout << "Y\n";
            return 0;
        }
        // shift
        if (l > 0) {
            if (sh < c) {
                int i = (sh + 1) % c;
                while (i != sh) {
                    if (!vis[l][i] && (s[i] & v[l]).none()) {
                        pq.push({l, i});
                        vis[l][i] = true;
                    } else {
                        break;
                    }
                    i = (i + 1) % c;
                }
                i = (sh - 1 + c) % c;
                while (i != sh) {
                    if (!vis[l][i] && (s[i] & v[l]).none()) {
                        pq.push({l, i});
                        vis[l][i] = true;
                    } else {
                        break;
                    }
                    i = (i - 1 + c) % c;
                }
            } else {
                int i = sh + 1;
                if (i == 2 * c) i = c;
                while (i != sh) {
                    if (!vis[l][i] && (s[i] & v[l]).none()) {
                        pq.push({l, i});
                        vis[l][i] = true;
                    } else {
                        break;
                    }
                    i++;
                    if (i == 2 * c) i = c;
                }
                i = sh - 1;
                if (i < c) i = 2 * c - 1;
                while (i != sh) {
                    if (!vis[l][i] && (s[i] & v[l]).none()) {
                        pq.push({l, i});
                        vis[l][i] = true;
                    } else {
                        break;
                    }
                    i--;
                    if (i < c) i = 2 * c - 1;
                }
            }
            // move up
            if (!vis[l - 1][sh] && (s[sh] & v[l - 1]).none()) {
                pq.push({l - 1, sh});
                vis[l - 1][sh] = true;
            }
        }
        // move down
        if ((s[sh] & v[l + 1]).none() && !vis[l + 1][sh]) {
            pq.push({l + 1, sh});
            vis[l + 1][sh] = true;
        }
    }
    cout << "N\n";
}
