#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    set<int> s;
    for (int i = 0; i < n; i++) {
        string x;
        cin >> x;
        if (x[0] != '-' && x.size() < 8) {
            s.insert(stoi(x));
        }
    }
    for (int i = 0; i <= n; i++) {
        if (!s.count(i)) {
            cout << i;
            return 0;
        }
    }
}
