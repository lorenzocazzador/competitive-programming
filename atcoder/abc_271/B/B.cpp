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

    int N, Q;
    cin >> N >> Q;
    vector<vi> v(N);
    for (int i = 0; i < N; i++) {
        int L;
        cin >> L;
        for (int j = 0; j < L; j++) {
            int x;
            cin >> x;
            v[i].push_back(x);
        }
    }
    while (Q--) {
        int S, T;
        cin >> S >> T;
        S--; T--;
        cout << v[S][T] << "\n";
    }
}
