#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef long long ll;

int main() {
    int n;
    cin >> n;
    if (n > 1 && n < 4) {
        cout << "NO SOLUTION\n";
    } else {
        for (int i = 2; i <= n; i += 2) cout << i << " ";
        for (int i = 1; i <= n; i += 2) cout << i << " ";
    }
}
