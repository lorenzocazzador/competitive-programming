#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int,int> pii;
typedef vector<pii> vii;
#define F first
#define S second
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define db(x) cout << #x << ": " << x << "\n";

int fact(int n) {
    int ans = 1;
    while (n > 0) {
        ans *= n;
        n--;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n = 4;
    vi a(n);
    cout << fact(n) << "\n";
    iota(all(a), 1);
    do {
        cout << n << "\n";
        for (int & x : a) cout << x << " ";
        cout << "\n";
    } while(next_permutation(all(a)));
}
