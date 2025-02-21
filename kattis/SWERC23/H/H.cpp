#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        for (int & x : a) cin >> x;
        for (int & x : b) cin >> x;
        int i, j;
        for (i = n - 1, j = n - 1; i >= 0 && j >= 0; i--, j--) {
            while (i >= 0 && a[i] != b[j]) i--;
            if (i == -1) break;
        }
        cout << j + 1 << "\n";
    }
}
