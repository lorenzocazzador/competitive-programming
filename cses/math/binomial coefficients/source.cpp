#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MOD = 1000000007, MAXN = 1000000;
ll fact[MAXN + 1], inv[MAXN + 1];

void calc_fact() {
    fact[0] = 1;
    for (int i = 1; i <= MAXN; i++) fact[i] = fact[i - 1] * i % MOD;
}

ll fast_exp(ll b, ll e) {
    ll res = 1;
    b %= MOD;
    while (e) {
        if (e & 1)
            res = res * b % MOD;
        b = b * b % MOD;
        e >>= 1;
    }
    return res;
}

void calc_inv() {
    inv[MAXN] = fast_exp(fact[MAXN], MOD - 2);
    for (int i = MAXN; i > 0; i--) inv[i - 1] = inv[i] * i % MOD;
}

ll nCr(ll n, ll r) {
    return fact[n] * inv[r] % MOD * inv[n - r] % MOD;
}

int main() {
    calc_fact();
    calc_inv();

    int n;
    cin >> n;
    while (n--) {
        int a, b;
        cin >> a >> b;
        cout << nCr(a, b) << "\n";
    }
}
