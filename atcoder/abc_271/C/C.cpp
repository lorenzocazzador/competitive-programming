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
    set<int> s;
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        s.insert(x);
    }
    int i = 0, rem = N;
    while (rem > 0) {
        i++;
        if (s.count(i)) {
            rem--;
        } else if (rem >= 2) {
            rem -= 2;
        } else {
            i--;
            break;
        }
    }
    cout << i << "\n";
}
