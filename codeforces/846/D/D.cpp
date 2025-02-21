#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef vector<pii> vii;
#define F first
#define S second
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define db(x) cout << #x << ": " << x << "\n";

void query(bool a, int x) {
    if (a) {
        cout << "! " << x << endl;
    } else {
        cout << "- " << x << endl;
    }
}

int get_ans() {
    int ans;
    cin >> ans;
    return ans;
}

void solve() {
    int s = 0, cnt, prec = -1, i = 0;
    vector<bool> zero(35, false);
    while (true) {
        cnt = get_ans();
        if (cnt == 0) {
            query(1, s);
            return;
        } else if (cnt == -1) {
            exit(0);
        } else {
            int t;
            if (prec == -1) {
                t = 1;
            } else {
                zero[i + cnt - prec + 1] = true;
                while (zero[i]) i++;
                t = (1 << i);
            }
            s += t;
            query(0, t);
        }
        prec = cnt;
    }
}

int main() {
    int t;
    cin >> t;
    while (t--)
        solve();
}
