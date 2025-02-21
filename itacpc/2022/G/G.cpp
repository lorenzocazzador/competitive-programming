#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn 200010
#define inf 1000000000000000000

int n;
ll v[maxn], ps[maxn], mim[maxn];

int trova(ll som) {
    int f = 0, t = n;
    while (f <= t) {
        int mid = (f + t) / 2;
        if (ps[mid] < som)
            f = mid + 1;
        else
            t = mid - 1;
    }
    return f - 1;
}

int main() {
    for (int i = 0; i < n; i++) {
        mim[i] = inf;
    }
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        ps[i] = ps[i - 1] + v[i];
    }

    ll tmin = 0, ris = inf;
    for (int i = 1; i <= n; i++) {
        tmin = min(tmin, mim[i]);

        int nex = trova(ps[i - 1] + tmin) + 1;
        cout << tmin << " " << nex << endl;
        ll sos = ps[nex] - ps[i - 1];
        mim[nex + 1] = min(mim[nex + 1], sos);

        if (nex + 1 > n) {
            ris = min(ris, sos);
        }

        tmin += v[i];
    }

    cout << ris << endl;
}
