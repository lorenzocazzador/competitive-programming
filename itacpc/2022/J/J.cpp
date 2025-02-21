#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn 1000010
#define pii pair<int, int>
#define fi first
#define se second

int n, m;
int v[maxn];
vector<int> dis[maxn];
pii coor[maxn];
int x, y;

int main() {
    // ifstream cin("input.txt");
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >>  v[i];
    }
    sort(v, v + m);
    cin >> x >> y >> n;
    for (int i = 0; i < n; i++) {
        cin >> coor[i].se >> coor[i].fi;
    }

    sort(coor, coor + n);

    int j = 0;
    for (int i = 0; i < n; i++) {
        while (j < m - 1 && v[j + 1] <= coor[i].fi)
            j++;
        cout << i << " -> " << j << "\n";
        if (v[j] > coor[i].fi) {
            dis[j].push_back(coor[i].se + v[j] - coor[i].fi);
        } else if (j <= m - 1) {
            if (coor[i].fi - v[j] < v[j + 1] - coor[i].fi) {
                dis[j].push_back(coor[i].se + coor[i].fi - v[j]);
            } else {
                dis[j].push_back(coor[i].se + v[j + 1] - coor[i].fi);
            }
        } else {
            dis[j].push_back(coor[i].se + coor[i].fi - v[j]);
        }
    }

    int mim = n + 1;
    for (int i = 0; i < m; i++) {
        sort(dis[i].begin(), dis[i].end());
        int d = abs(y - v[i]) + x;
        auto it = upper_bound(dis[i].begin(), dis[i].end(), d);
        mim = min(mim, (int)(it - dis[i].begin()));
    }
    cout << mim << endl;
}
