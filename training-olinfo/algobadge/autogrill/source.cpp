#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
set<ll> s;

void inizia() {
    s.clear();
}

void apri(ll p) {
    s.insert(p);
}

void chiudi(ll p) {
    s.erase(p);
}

long long chiedi(ll p) {
    if (s.empty()) return -1;
    auto l = s.lower_bound(p), u = s.upper_bound(p);
    while (l != s.begin() && *l > p) {
        l--;
    }
    if (l == s.begin()) {
        return *u;
    }
    if (u == s.end()) {
        return *l;
    }
    if (abs(*l - p) < abs(*u - p)) {
        return *l;
    } else {
        return *u;
    }
}

int main() {
    int q;
    cin >> q;
    while (q--) {
        char t; ll p;
        cin >> t >> p;
        if (t == 'a') apri(p);
        else if (t == 'c') chiudi(p);
        else if (t == 'q') cout << chiedi(p) << "\n";
    }
}
