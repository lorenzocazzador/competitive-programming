#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    double res = 0;
    while (n--) {
        int p;
        cin >> p;
        vector<array<double, 2>> a(p);
        for (int i = 0; i < p; i++) {
            cin >> a[i][0] >> a[i][1];
        }
        double tmp = 0;
        for (int i = 0; i < p; i++) {
            int j = (i == 0 ? p - 1 : i - 1);
            tmp += (a[j][0] - a[i][0]) * (a[j][1] + a[i][1]) / 2.0;
        }
        res += fabs(tmp);
    }
    cout << (long long)res << "\n";
}
