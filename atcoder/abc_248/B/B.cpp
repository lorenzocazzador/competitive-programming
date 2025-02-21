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

void solve() {

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll A, B, K;
    cin >> A >> B >> K;
    ll ans = 0;
    while (A < B) {
        A *= K;
        ans++;
    }
    cout << ans << "\n";
}
