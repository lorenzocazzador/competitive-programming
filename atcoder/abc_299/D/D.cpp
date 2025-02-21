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

int query(int x) {
    cout << "? " << x << endl;
    int ans;
    cin >> ans;
    return ans;
}

int main() {
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    int a = 1, b = n, mid, ans;
    while (a < b - 1) {
        mid = (a + b) / 2;
        ans = query(mid);
        if (ans == 0) {
            a = mid;
        } else {
            b = mid;
        }
    }
    mid = (a + b) / 2;
    cout << "! " << mid << endl;
}
