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

    int N, S;
    cin >> N >> S;
    vii v(N);
    for (pii & x : v) cin >> x.F >> x.S;
    vector<vi> r(N, vector<int>(S + 1, -1));
    r[0][v[0].F] = v[0].F;
    r[0][v[0].S] = v[0].S;
    for (int i = 1; i < N; i++) {
        for (int j = S; j >= 1; j--) {
            if (r[i-1][j] != -1) {
                if (j + v[i].F <= S)
                    r[i][j + v[i].F] = v[i].F;
                if (j + v[i].S <= S)
                    r[i][j + v[i].S] = v[i].S;
            }
        }
    }
    cout << (r[N - 1][S] != -1 ? "Yes" : "No") << "\n";
    if (r[N - 1][S] != -1) {
        string res = "";
        int j = S;
        for (int i = N - 1; i >= 0; i--) {
            if (r[i][j] == v[i].F)
                res = "H" + res;
            else
                res = "T" + res;
            j -= r[i][j];
        }
        cout << res << "\n";
    }
}
