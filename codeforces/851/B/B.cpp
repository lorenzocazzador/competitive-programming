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


void solve() {
    string n;
    cin >> n;
    int sa = 0, sb = 0;
    string a = "", b = "";
    for (char & c : n) {
        int x = c - '0';
        if (x % 2) {
            char l = (x / 2) + '0', r = (x / 2 + (x % 2)) + '0';
            if (sa > sb) {
                a += l;
                b += r;
                sa += x / 2;
                sb += x / 2 + (x % 2);
            } else {
                a += r;
                b += l;
                sa += x / 2 + (x % 2);
                sb += x / 2;
            }
        } else {
            char t = (x / 2) + '0';
            a += t;
            b += t;
            sa += x / 2;
            sb += x / 2;
        }
    }
    cout << stoi(a) << " " << stoi(b) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while(T--) solve();
}
