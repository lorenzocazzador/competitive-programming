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

    int n; string s;
    cin >> n >> s;
    int a = -1, b = -1, c = -1;
    for (int i = 0; i < n; i++) {
        if (s[i] == '|') {
            if (a == -1) a = i;
            else b = i;
        } else if (s[i] == '*') c = i;
    }
    cout << (a < c && c < b ? "in\n" : "out\n");
}
