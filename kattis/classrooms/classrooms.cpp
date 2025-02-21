#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<array<int,3>> v(n);
    multiset<array<int, 2>> m;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        m.insert({((a + b - a) / 2, a, b});
    }
    int res = 0;
    for (int i = 0; i < k; i++) {
        // cout << "i -> " << i << "\n";
        array<int, 2> l = {0, 0};
        auto it = m.lower_bound(l);
        while (it != m.end()) {
            if ((*it)[0] <= l[1]) {
                it++;
            } else {
                // cout << (*it)[0] << " " << (*it)[1] << "\n";
                res++;
                l = *it;
                m.erase(it);
                it = m.lower_bound(l);
            }
        }
    }
    cout << res << "\n";
}
