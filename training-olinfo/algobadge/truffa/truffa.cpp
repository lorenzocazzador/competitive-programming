#include <bits/stdc++.h>
using namespace std;

int main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    vector<int> v(n);
    int sum = 0;
    for (int & x : v) {
        cin >> x;
        sum += x;
    }
    sort(v.begin(), v.end());
    int i = 0;
    while(i < n && sum <= 0) {
        sum += -v[i] * 2;
        i++;
    }
    cout << i << "\n";
}
