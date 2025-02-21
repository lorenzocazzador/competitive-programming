#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    string a, b;
    cin >> a >> b;
    vector<int> f1, f2;
    for (int i = 0; i < n; i++) {
        if (a[i] == '1')
            f2.push_back(i + 1);
        if (b[i] == '1')
            f1.push_back(i + 1);
    }
    int ans = INT_MAX, f, t;
    for (int j = 1; j <= 2; j++) {
        for (int i = 1; i <= n; i++) {
            int tmp = 0;
            if (j == 1) {
                if (f1.size())
                    tmp = max(abs(i - f1.front()), abs(i - f1.back()));
                if (f2.size())
                    tmp = max(tmp, i + f2.back() + k);
            } else {
                if (f2.size())
                    tmp = max(abs(i - f2.front()), abs(i - f2.back()));
                if (f1.size())
                    tmp = max(tmp, i + f1.back() + k);
            }
            if (tmp < ans) {
                ans = tmp;
                f = j;
                t = i;
            }
        }
    }
    cout << ans << "\n" << f << " " << t << "\n";
}
