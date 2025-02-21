#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        int n, f, c;
        cin >> n >> f >> c;
        cout << "Case #" << i << ": " << n / f << " " << (n % f) / c << "\n";
    }
}
