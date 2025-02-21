#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (int &x : a)
        cin >> x;
    int t = 1, mx = 1;
    for (int i = 0; i < n - 1; i++) {
        if (a[i + 1] - a[i] > x) {
            mx = max(mx, t);
            t = 1;
        } else
            t++;
    }
    cout << max(t, mx) << "\n";
}
