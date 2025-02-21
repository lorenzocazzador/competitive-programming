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
map<char, char> prec, succ;

char getNext(char c) {
    char end = c; int j = 0;
    while (succ.count(end)) {
        j++;
        end = succ[end];
    }
    if (j == 25) return end;
    for (int i = 0; i < 26; i++) {
        char x = 'a' + i;
        if (x != end && x != c && succ.count(x) == 0)
            return x;
    }
}

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    string res = "";

    prec.clear();
    succ.clear();

    for (char & c : s) {
        if (prec.count(c)) {
            res += prec[c];
        } else {
            char x = getNext(c);
            prec[c] = x;
            succ[x] = c;
            res += prec[c];
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
