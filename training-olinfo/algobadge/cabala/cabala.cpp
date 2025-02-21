#include <bits/stdc++.h>
using namespace std;

long long number, res;

void solve(int N, int M) {
    if (number % M > res % M && number != 0)
        res = number;

    if (N == 0)
        return;

    for (auto &x : {3, 6, 9}) {
        if (number % 10 == x)
            continue;

        number *= 10;
        number += x;
        solve(N - 1, M);
        number -= x;
        number /= 10;
    }
}

long long occulta(int N, int M) {
    number = 0;
    res = 0;
    solve(N, M);
    cout << res << "\n";
    return res % M;
}

int main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int T;
    cin >> T;
    while (T--) {
        int N, M;
        cin >> N >> M;
        cout << occulta(N, M) << " ";
    }
}
