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


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> k >> n;
    vi  s(n);
    vi occ(1010, 0);
    for (int & x : s) {
        cin >> x;
        occ[x]++;
    }
    int d, a;
    if ((n - 1) % k == 0) {
        d = (n - 1) / k;
        a = -1;
        for (int i = 1; i <= k; i++) {
            if (occ[i] - 1 == d && a == -1) {
                a = i;
            } else if (occ[i] != d) {
                return cout << "*\n", 0;
            }
        }
        if (a == -1 || d == 0) cout << "*\n";
        else cout << "-" << a << "\n";
    } else if ((n + 1) % k == 0) {
        d = (n + 1) / k;
        a = -1;
        for (int i = 1; i <= k; i++) {
            if (occ[i] + 1 == d && a == -1) {
                    a = i;
            } else if (occ[i] != d) {
                return cout << "*\n", 0;
            }
        }
        if (a == -1 || d == 0) cout << "*\n";
        else cout << "+" << a << "\n";
    } else if (n % k == 0) {
        d = n / k;
        a = -1;
        int b = -1;
        for (int i = 1; i <= k; i++) {
            if (occ[i] - 1 == d && a == -1) {
                a = i;
            } else if (occ[i] + 1 == d && b == -1) {
                b = i;
            } else if (occ[i] != d){
                return cout << "*\n", 0;
            }
        }
        if (a == -1 || b == -1 || d == 0) cout << "*\n";
        else cout << "-" << a << " +" << b << "\n";
    } else cout << "*\n";
}
