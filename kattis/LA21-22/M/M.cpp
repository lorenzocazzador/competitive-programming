#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll INF = 1e18;

struct Assignment {
    ll t, d, id;
    Assignment(int t = 0, int d = 0, int id = 0) : t(t), d(d), id(id) {}
};

bool operator<(const Assignment &lhs, const Assignment &rhs) {
    return (lhs.d == rhs.d) ? lhs.id < rhs.id : lhs.d < rhs.d;
}

signed main() {
#ifdef LOCAL_INPUT
    ifstream cin("input.txt");
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<Assignment> ass;
    for (int i = 0; i < n; i++) {
        int t, d;
        cin >> t >> d;
        ass.push_back(Assignment(t, d, i));
    }
    sort(ass.begin(), ass.end());
    ll sum = 0, mim_id, mim_j;
    for (Assignment a : ass) {
        sum += a.t;
        if (a.d < sum) {
            cout << "*" << endl;
            return 0;
        }
    }
    vector<ll> pref_mim(n + 1);
    for (int i = 0; i < n; i++) {
        mim_id = INF;
        sum = 0;
        for (int j = 0; j < i; j++) {
            sum += ass[j].t;
            pref_mim[j] = INF;
        }
        for (int j = i; j < n; j++) {
            sum += ass[j].t;
            pref_mim[j] = min(pref_mim[j - 1], ass[j].d - sum);
            if (ass[j].id < mim_id && ass[j].t <= pref_mim[j - 1]) {
                mim_id = ass[j].id;
                mim_j = j;
            }
        }
        if (mim_id != INF) {
            Assignment first = ass[mim_j];
            ass.erase(ass.begin() + mim_j);
            ass.insert(ass.begin() + i, 1, first);
        }
    }
    for (Assignment a : ass)
        cout << a.id + 1 << " ";
    cout << endl;

#ifdef LOCAL_INPUT
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}
