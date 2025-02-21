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

    int N;
    cin >> N;
    string res = "";
    int R = N / 16;
    N = N % 16;
    if (R > 9) {
        res += 'A' + (R - 10);
    } else res += to_string(R);
    if (N > 9) {
        res += 'A' + (N - 10);
    } else res += to_string(N);
    cout << res << "\n";
}
