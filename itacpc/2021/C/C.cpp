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

bool intersect (pii a, pii b) {
    return (b.F <= a.S && a.S <= b.S) || (b.F <= a.F && a.F <= b.S) || (a.F <= b.F && b.S <= a.S);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vii A(n);
    for (pii & x : A) cin >> x.F >> x.S;
    bool ans = true;
    for (int i = 1; i < n; i++)
        ans &= (intersect(A[i-1], A[i]) || intersect(A[i], A[i-1]));
    cout << (ans ? "YES" : "NO") << "\n";
}
