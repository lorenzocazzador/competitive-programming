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

vector<int> manacher_odd(string s) {
    int n = s.size();
    s = "$" + s + "^";
    vector<int> p(n + 2);
    int l = 1, r = 1;
    for(int i = 1; i <= n; i++) {
        p[i] = max(0, min(r - i, p[l + (r - i)]));
        while(s[i - p[i]] == s[i + p[i]]) {
            p[i]++;
        }
        if(i + p[i] > r) {
            l = i - p[i], r = i + p[i];
        }
    }
    return vector<int>(begin(p) + 1, end(p) - 1);
}

vector<int> manacher(string s) {
    string t;
    for(auto c: s) {
        t += string("#") + c;
    }
    auto res = manacher_odd(t + "#");
    return vector<int>(begin(res) + 1, end(res) - 1);
}

vector<int> manacherL(const string& s) {
    const int n = (int)s.length();
    if (n == 0)
        return vector<int>();
    vector<int> res(2*n - 1);
    int p = 0, pR = -1;
    for (int pos = 0; pos < 2*n - 1; ++pos) {
        int R = pos <= 2*pR ? min(p - res[2*p - pos], pR) : pos/2;
        int L = pos - R;
        while (L > 0 && R < n-1 && s[L-1] == s[R+1]) {
            --L;
            ++R;
        }
        res[pos] = L;
        if (R > pR) {
            pR = R;
            p = pos;
        }
    }
    for (int i = 0; i < sz(res); i++) res[i] = i - 2*res[i] + 1;
    return res;
}

vi man_odd, man_even;
void prec(string s) {
    man_odd.clear();
    man_even.clear();
    man_odd.resize(sz(s));
    man_even.resize(sz(s));
    auto vec = manacherL(s);
    for (int i = 0; i < sz(vec); i++) {
        if (i % 2 == 0) {
            man_even[i / 2] = vec[i];
        } else {
            man_odd[i / 2] = vec[i];
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<string> a;
    set<string> s;
    for (int i = 0; i < n; i++) {
        string x;
        cin >> x;
        s.insert(x);
        a.push_back(x);
    }
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        string t = "", x = "";
        prec(a[i]);
        int l = sz(a[i]);
        for (int j = 0; j < l; j++) {
            t = a[i][j] + t;
            if (s.find(t) != s.end()) {
                int len = l - j - 1;
                int cen = j + len / 2 + 1;
                if (len <= 1) {
                    ans++;
                } else if (len % 2 == 0) {
                    ans += (man_even[cen] * 2 >= len);
                } else {
                    ans += (man_odd[cen] * 2 - 1 >= len);
                }
            }

            x += a[i][l-j-1];
            if (s.find(x) != s.end()) {
                int len = l - j - 1;
                int cen = len / 2;
                if (len > 0 && len % 2 == 0) {
                    ans += (man_even[cen] * 2 >= len);
                } else {
                    ans += (man_odd[cen] * 2 - 1 >= len);
                }
            }
        }
    }
    cout << ans  << "\n";
}
