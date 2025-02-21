#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef long long ll;

int main() {
    int n, q;
    cin >> n >> q;
    vector<vi> f(n + 1, vi(n + 1));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            char c;
            cin >> c;
            f[i + 1][j + 1] = (c == '*');
        }
    }
    vector<vi> prefix_sum(n + 1, vi(n + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            prefix_sum[i][j] = prefix_sum[i - 1][j] + prefix_sum[i][j - 1] -
                               prefix_sum[i - 1][j - 1] + f[i][j];
        }
    }
    while (q--) {
        int y1, x1, y2, x2;
        cin >> y1 >> x1 >> y2 >> x2;
        cout << prefix_sum[y2][x2] - prefix_sum[y1 - 1][x2] -
                    prefix_sum[y2][x1 - 1] + prefix_sum[y1 - 1][x1 - 1]
             << "\n";
    }
}
