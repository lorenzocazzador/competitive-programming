#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef long long ll;

int main() {
    ll n, sum = 0;
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        ll x;
        cin >> x;
        sum += x;
    }
    cout << n * (n + 1) / 2 - sum << "\n";
}
