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

set<char> nextL;
map<char, int> m;
vector<char> v;

char getNext(char c) {
    auto it = nextL.begin();
    while (*it == c) {
        it++;
    }
    return *it;
}

void assign(char c, int ind) {
    // cout << c << " -> " << ind << "\n";
    assert(ind >= 0 && ind < 26);
    nextL.erase(c);
    v[ind] = c;
    m[v[ind]] = ind;
}

int getMinFree() {
    int ind = -1;
    for (int i = 0; i < 25; i++) {
        if (v[i] != '0' && v[i + 1] == '0') {
            if (ind == -1) ind = i;
            else if (v[i] < v[ind]) ind = i;
        }
    }
    if (v[0] == '0' && v[25] != '0' && v[25] < v[ind]) ind = 25;
    return ind;
}

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    string res = "";

    nextL.clear();
    v.clear();
    m.clear();
    v.resize(26, '0');

    for (int i = 0; i < 26; i++) {
        nextL.insert('a' + i);
    }

    for (char & c : s) {
        if (m.count(c)) {
            int ind = (m[c] > 0 ? m[c] - 1 : 25);
            if (v[ind] == '0') {
                assign(getNext(c), ind);
            }
            res += v[ind];
        } else {
            int ind = getMinFree();
            char nx = getNext(c);
            if (ind != -1 && v[ind] < nx) {
                assign(c, (ind + 1) % 26);
                res += v[ind];
            } else {
                for (int i = 0; i < 26; i++) {
                    if (v[i] == '0' && v[(i + 1) % 26] == '0') {
                        assign(nx, i);
                        assign(c, (i + 1) % 26);
                        break;
                    }
                }
                res += nx;
            }
        }
    }
    cout << res << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while(T--) solve();
}
