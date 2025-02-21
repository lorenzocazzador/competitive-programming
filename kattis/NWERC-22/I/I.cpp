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

    int c, d;
    cin >> c >> d;
    vi fi, bu, fb;
    for (int i = c; i <= d; i++) {
        string s;
        cin >> s;
        if (s == "Fizz") {
            fi.push_back(i);
        } else if (s == "Buzz") {
            bu.push_back(i);
        } else if (s == "FizzBuzz") {
            fb.push_back(i);
        }
    }
    int a = -1, b = -1;
    if (sz(fi)) {
        a = fi[0];
        for(int i = 1; i < sz(fi); i++) a = __gcd(a, fi[i]);
    }
    if (sz(bu)) {
        b = bu[0];
        for(int i = 1; i < sz(bu); i++) b = __gcd(b, bu[i]);
    }
    if (sz(fb)) {
        if (a == -1) a = fb[0];
        if (b == -1) b = fb[0];
        for (int i = 0; i < sz(fb); i++) {
            a = __gcd(a, fb[i]);
            b = __gcd(b, fb[i]);
        }
    }
    cout << (a == -1 ? d + 1 : a) << " " << (b == -1 ? d + 1 : b) << "\n";
}
