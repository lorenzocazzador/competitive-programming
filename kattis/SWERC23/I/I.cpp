#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef pair<ld, ld> pdd;
#define F first
#define S second
#define sz(s) (int)s.size()

int n;
vector<pdd> v;

ld trap(pdd a, pdd b) {
    return 0.5 * (a.F - b.F) * (a.S + b.S);
}

ld triarea(int a, int b, int c) {
    return fabs(trap(v[a], v[b]) + trap(v[b], v[c]) + trap(v[c], v[a]));
}


int main() {
    cin >> n;
    v.resize(n);
    for (auto & x : v) cin >> x.F >> x.S;
    if (n % 2) {
        cout << "Beatrice" << endl;
    } else {
        cout << "Alberto" << endl;
    }
    bool b = (n % 2) == 0, t = 1;
    vector<int> rem(n);
    for (int i = 0; i < n; i++) rem[i] = i;
    for (int i = 0; i < n - 2; i++) {
        int to_rem = 0;
        if (b == t) {
            ld mim = -1;
            int best = 0;
            for (int i = 0; i < sz(rem); i++) {
                int a = (i - 1 >= 0 ? i - 1 : sz(rem) - 1);
                int c = (i + 1 < sz(rem) ? i + 1 : 0);
                ld area = triarea(rem[a], rem[i], rem[c]);
                if (mim == -1 || area < mim) {
                    mim = area;
                    best = rem[i];
                }
            }
            cout << best + 1 << endl;
            to_rem = best;
        } else {
            cin >> to_rem;
            to_rem--;
        }
        vector<int> new_rem;
        for (int & x : rem) {
            if (x != to_rem) {
                new_rem.push_back(x);
            }
        }
        rem = new_rem;
        t = !t;
    }
}
