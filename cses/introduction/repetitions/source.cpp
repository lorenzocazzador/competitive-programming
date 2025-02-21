#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef long long ll;

int main() {
    string s;
    cin >> s;
    int ans = 1, tmp = 1;
    for (int i = 1; i < (int)s.size(); i++) {
        if (s[i] == s[i-1]) {
            tmp++;
            ans = max(ans, tmp);
        } else {
            tmp = 1;
        }
    }
    cout << ans << "\n";
}
