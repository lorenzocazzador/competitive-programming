#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;
    int w = 0, ans = 0;
    for (int i = 0; i < 2 * n - 1; i++) {
        w += s[i] == 'W';
        if (i >= n) w -= s[i - n] == 'W';
        ans = max(ans, w);
    }
    cout << ans << "\n";
}
