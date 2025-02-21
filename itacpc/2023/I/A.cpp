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

    int n, d;
    cin >> d >> n;
    string s = "";
    ll ans = d;
    for (int i = 2; i <= n; i++)
        ans = ans * 2 + (i / 10) + (i % 10);
    cout << ans << "\n";
}
